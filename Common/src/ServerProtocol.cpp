#include <ServerProtocol.h>

namespace protocol
{
    class Action
    {
    public:
        Action(PlayerEnum playerSource, MessageType messageType)
            : playerSource(playerSource), messageType(messageType) {}
        PlayerEnum playerSource;
        MessageType messageType;
    };

    class Movement : public Action
    {
    public:
        Movement(PlayerEnum playerSource, LocationTypeEnum locationType, LocationEnum location)
            : Action(playerSource, MessageType::MOVEMENT), locationType(locationType), location(location) {}
        LocationTypeEnum locationType;
        LocationEnum location;
    };

    class Suggestion : public Action
    {
    public:
        Suggestion(PlayerEnum playerSource, PlayerEnum playerSuggested, LocationEnum location, WeaponEnum weapon)
            : Action(playerSource, MessageType::SUGGESTION), playerSuggested(playerSuggested), location(location), weapon(weapon) {}
        PlayerEnum playerSuggested;
        LocationEnum location;
        WeaponEnum weapon;
    };

    class Accusation : public Action
    {
    public:
        Accusation(PlayerEnum playerSource, PlayerEnum playerAccused, LocationEnum location, WeaponEnum weapon)
            : Action(playerSource, MessageType::ACCUSATION), playerAccused(playerAccused), location(location), weapon(weapon) {}
        PlayerEnum playerAccused;
        LocationEnum location;
        WeaponEnum weapon;
    };

    class Refutation : public Action
    {
    public:
        Refutation(PlayerEnum playerSource, PlayerEnum playerRefuted, CardEnum card)
            : Action(playerSource, MessageType::REFUTATION), playerRefuted(playerRefuted), card(card) {}
        PlayerEnum playerRefuted;
        CardEnum card;
    };

    class Initialization : public Action
    {
    public:
        Initialization() : Action(PlayerEnum::SERVER, MessageType::INITIALIZATION) {}
        // Constructor would be too complicated if it took parameters. Instead, construct empty and add parameters.
        int numConnected;
        Player * players[6];
    };

    class PlayerConnect : public Action
    {
    public:
        PlayerConnect(PlayerEnum playerAssignment)
            : Action(PlayerEnum::SERVER, MessageType::PLAYER_CONNECT), playerAssignment(playerAssignment) {}
        PlayerEnum playerAssignment;
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
        ba[4] = accusation.playerAccused;
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
        ba.resize(39);
        ba[0] = 0x27;
        ba[1] = 0x00;
        ba[2] = MessageType::INITIALIZATION;
        for (int i = 0; i < 6; ++i)
        {
            ba[3+5*i] = init.players[i]->getCurrentLocation()->getBoardElementEnum();
            ba[4+5*i] = init.players[i]->getHandCards()[0]->getCardType();
            ba[5+5*i] = init.players[i]->getHandCards()[1]->getCardType();
            ba[6+5*i] = init.players[i]->getHandCards()[2]->getCardType();
            ba[7+5*i] = init.players[i]->isConnected(); // boolean gives 0 or 1 (false, true).
        }
        ba[38] = init.numConnected;
        return ba;
    }

    QByteArray form_player_connect(PlayerConnect conn)
    {
        QByteArray ba;
        ba.resize(4);
        ba[0] = 0x04;
        ba[1] = 0x00;
        ba[2] = MessageType::PLAYER_CONNECT;
        ba[3] = conn.playerAssignment;
        return ba;
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
        MessageType messageType = (MessageType)(int)ba[2];


        switch(messageType) // No 'break' means all cases continue to default.
        {
        case MessageType::MOVEMENT :
            if (messageLength < 6)
            {
                return action;
            }
            action = new Movement((PlayerEnum)(int)ba[3], (LocationTypeEnum)(int)ba[4], (LocationEnum)(int)ba[5]);
        case MessageType::SUGGESTION :
            if (messageLength < 7)
            {
                return action;
            }
            action = new Suggestion((PlayerEnum)(int)ba[3], (PlayerEnum)(int)ba[4], (LocationEnum)(int)ba[5], (WeaponEnum)(int)ba[6]);
        case MessageType::ACCUSATION :
            if (messageLength < 7)
            {
                return action;
            }
            action = new Accusation((PlayerEnum)(int)ba[3], (PlayerEnum)(int)ba[4], (LocationEnum)(int)ba[5], (WeaponEnum)(int)ba[6]);
        case MessageType::REFUTATION :
            if (messageLength < 6)
            {
                return action;
            }
            action = new Refutation((PlayerEnum)(int)ba[3], (PlayerEnum)(int)ba[4], (CardEnum)(int)ba[5]);
        case MessageType::INITIALIZATION :
        {
            // This one is MUCH more aggressive. This actually *sets* all the values on the board.
            Board* board = Board::getInstance();
            if (messageLength < 39)
            {
                return action;
            }
            Initialization* init = new Initialization();
            for (int i = 0; i < 6; ++i)
            {
                init->players[i] = board->getPlayer((PlayerEnum)i);
                init->players[i]->move(board->getBoardElement((LocationEnum)(int)ba[3+5*i]));
                init->players[i]->giveCard(board->getCard((CardEnum)(int)ba[4+5*i]));
                init->players[i]->giveCard(board->getCard((CardEnum)(int)ba[5+5*i]));
                init->players[i]->giveCard(board->getCard((CardEnum)(int)ba[6+5*i]));
                init->players[i]->setConnected((bool)(int)ba[7+5*i]);
            }
            init->numConnected = ba[38];
            action = (Action *)&init;
        }
        case MessageType::PLAYER_CONNECT :
            if (messageLength < 4)
            {
                return action;
            }
            action = new PlayerConnect((PlayerEnum)(int)ba[3]);
        default:
            return action;
        }
    }
}

#endif // SERVERPROTOCOL_H
