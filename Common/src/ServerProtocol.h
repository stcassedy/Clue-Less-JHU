#ifndef SERVERPROTOCOL_H
#define SERVERPROTOCOL_H

#include <QByteArray>
#include <BoardEnums.h>
#include <Board.h>
#include <Player.h>

namespace protocol
{
    enum MessageType
    {
        MOVEMENT = 0x10,
        SUGGESTION,
        ACCUSATION,
        REFUTATION,
        INITIALIZATION = 0x20
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

    class Initialization : public Action
    {
        Initialization() : Action(PlayerEnum::SERVER, MessageType::INITIALIZATION) {}
        // Constructor would be too complicated if it took parameters. Instead, construct empty and add parameters.
        int numConnected;
        Player * players[6];
    };

    QByteArray form_movement(Movement movement)
    {
        QByteArray ba;
        ba.resize(6);
        ba[0] = 0x06;
        ba[1] = 0x00;
        ba[2] = MessageType::MOVEMENT;
        ba[3] = movement.playerSource;
        ba[4] = movement.locationType;
        ba[5] = movement.location;
        return ba;
    }

    QByteArray form_suggestion(Suggestion suggestion)
    {
        QByteArray ba;
        ba.resize(7);
        ba[0] = 0x07;
        ba[1] = 0x00;
        ba[2] = MessageType::SUGGESTION;
        ba[3] = suggestion.playerSource;
        ba[4] = suggestion.playerSuggested;
        ba[5] = suggestion.location;
        ba[6] = suggestion.weapon;
        return ba;
    }

    QByteArray form_accusation(Accusation accusation)
    {
        QByteArray ba;
        ba.resize(7);
        ba[0] = 0x07;
        ba[1] = 0x00;
        ba[2] = MessageType::ACCUSATION;
        ba[3] = accusation.playerSource;
        ba[4] = accusation.playerSuggested;
        ba[5] = accusation.location;
        ba[6] = accusation.weapon;
        return ba;
    }

    QByteArray form_refutation(Refutation refutation)
    {
        QByteArray ba;
        ba.resize(5);
        ba[0] = 0x06;
        ba[1] = 0x00;
        ba[2] = MessageType::REFUTATION;
        ba[3] = refutation.playerSource;
        ba[4] = refutation.playerRefuted;
        ba[5] = refutation.card;
        return ba;
    }

    QByteArray form_initialization(Initialization init)
    {
        QByteArray ba;
        ba[0] = 0x27;
        ba[1] = 0x00;
        ba[2] = MessageType::INITIALIZATION;
        for (int i = 0; i < 6; ++i)
        {
            ba[3+5*i] = init.players[i]->getCurrentLocation()->getBoardElementEnum;
            ba[4+5*i] = init.players[i]->getHandCards()[0]->getCardType();
            ba[5+5*i] = init.players[i]->getHandCards()[1]->getCardType();
            ba[6+5*i] = init.players[i]->getHandCards()[2]->getCardType();
            ba[7+5*i] = init.players[i]->isConnected(); // boolean gives 0 or 1 (false, true).
        }
        ba[38] = init.numConnected;

    }

    // Use DerivedClass * c = static_cast<DerivedClass>(baseClassPointer) to retrieve the derived class
    // once you've checked baseClassPointer->messageType.
    Action * parse_message(QByteArray ba)
    {
        Action * action = NULL;

        int messageLength = ba[0] + 16 * ba[1];
        if (messageLength < 3)
        {
            return action;
        }
        MessageType messageType = ba[2];


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
        case MessageType::INITIALIZATION :
            // This one is MUCH more aggressive. This actually *sets* all the values on the board.
            if (messageLength < 39)
            {
                return action;
            }
            Initialization* init = new Initialization();
            for (int i = 0; i < 6; ++i)
            {
                init->players[i] = Board::getPlayer(i);
                init->players[i]->move(Board::getBoardElement(ba[3+5*i]));
                init->players[i]->giveCard(Board::getCard(ba[4+5*i]));
                init->players[i]->giveCard(Board::getCard(ba[5+5*i]));
                init->players[i]->giveCard(Board::getCard(ba[6+5*i]));
                init->players[i]->setConnected(ba[7+5*i]);
            }
            init->numConnected = ba[38];
            action = &init;
        default:
            return action;
    }
}

#endif // SERVERPROTOCOL_H
