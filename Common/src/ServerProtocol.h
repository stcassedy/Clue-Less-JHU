#ifndef SERVERPROTOCOL_H
#define SERVERPROTOCOL_H

#include <QByteArray>
#include <BoardEnums.h>

namespace protocol
{
    enum MessageType
    {
        MOVEMENT = 0x10,
        SUGGESTION,
        ACCUSATION,
        REFUTATION
    };

    class Action
    {
        Action(PlayerEnum playerSource, MessageType messageType)
            : playerSource(playerSource), messageType(messageType) {}
        PlayerEnum playerSource;
        MessageType messageType;
    };

    class Movement : public Action
    {
        Movement(PlayerEnum playerIndex, LocationTypeEnum locationType, LocationEnum location)
            : Action(playerSource, MessageType::MOVEMENT), playerIndex(playerIndex), locationType(locationType), location(location) {}
        LocationTypeEnum locationType;
        LocationEnum location;
    };

    class Suggestion : public Action
    {
        Suggestion(PlayerEnum playerSource, PlayerEnum playerSuggested, LocationEnum location, WeaponEnum weapon)
            : Action(playerSource, MessageType::MOVEMENT), playerSource(playerSource), playerSuggested(playerSuggested), location(location), weapon(weapon) {}
        PlayerEnum playerSuggested;
        LocationEnum location;
        WeaponEnum weapon;
    };

    class Accusation : public Action
    {
        Accusation(PlayerEnum playerSource, PlayerEnum playerAccused, LocationEnum location, WeaponEnum weapon)
            : Action(playerSource, MessageType::MOVEMENT), playerSource(playerSource), playerAccused(playerAccused), location(location), weapon(weapon) {}
        PlayerEnum playerAccused;
        LocationEnum location;
        WeaponEnum weapon;
    };

    class Refutation : public Action
    {
        Refutation(PlayerEnum playerSource, PlayerEnum playerRefuted, CardEnum card)
            : Action(playerSource, MessageType::MOVEMENT), playerSource(playerSource), playerRefuted(playerRefuted), card(card) {}
        PlayerEnum playerRefuted;
        CardEnum card;
    };

    QByteArray form_movement(PlayerEnum playerIndex, LocationTypeEnum locationType, LocationEnum location)
    {
        QByteArray ba;
        ba.resize(6);
        ba[0] = 0x06;
        ba[1] = 0x00;
        ba[2] = MessageType::MOVEMENT;
        ba[3] = playerIndex;
        ba[4] = locationType;
        ba[5] = location;
        return ba;
    }

    QByteArray form_suggestion(PlayerEnum playerSource, PlayerEnum playerSuggested, LocationEnum location, WeaponEnum weapon)
    {
        QByteArray ba;
        ba.resize(7);
        ba[0] = 0x07;
        ba[1] = 0x00;
        ba[2] = MessageType::SUGGESTION;
        ba[3] = playerSource;
        ba[4] = playerSuggested;
        ba[5] = location;
        ba[6] = weapon;
        return ba;
    }

    QByteArray form_accusation(PlayerEnum playerSource, PlayerEnum playerSuggested, LocationEnum location, WeaponEnum weapon)
    {
        QByteArray ba;
        ba.resize(7);
        ba[0] = 0x07;
        ba[1] = 0x00;
        ba[2] = MessageType::ACCUSATION;
        ba[3] = playerSource;
        ba[4] = playerSuggested;
        ba[5] = location;
        ba[6] = weapon;
        return ba;
    }

    QByteArray form_refutation(PlayerEnum playerSource, PlayerEnum playerRefuted, CardEnum card)
    {
        QByteArray ba;
        ba.resize(5);
        ba[0] = 0x06;
        ba[1] = 0x00;
        ba[2] = MessageType::REFUTATION;
        ba[3] = playerSource;
        ba[4] = playerRefuted;
        ba[5] = card;
        return ba;
    }

    Action * parse_message(QByteArray ba)
    {
        Action * action = NULL;

        messageLength = ba[0] + 16 * ba[1];
        if (messageLength < 3)
        {
            return action;
        }
        messageType = ba[2];


        switch(messageType): // No 'break' means all cases continue to default.

        case MessageType::MOVEMENT :
            if (messageLength < 6)
            {
                return action;
            }
            action = new Movement(ba[3], ba[4], ba[5]);
        case MessageType::SUGGESTION :
            if (messageLength < 7)
            {
                return action;
            }
            action = new Suggestion(ba[3], ba[4], ba[5], ba[6]);
        case MessageType::ACCUSATION :
            if (messageLength < 7)
            {
                return action;
            }
            action = new Accusation(ba[3], ba[4], ba[5], ba[6]);
        case MessageType::REFUTATION :
            if (messageLength < 6)
            {
                return action;
            }
            action = new Refutation(ba[3], ba[4], ba[5]);
        default:
            return action;
    }
}

#endif // SERVERPROTOCOL_H
