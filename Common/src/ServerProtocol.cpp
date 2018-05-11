#include "ServerProtocol.h"

namespace protocol
{
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
        ba.resize(35);
        int i = -1;
        ba[++i] = 0x23;
        ba[++i] = 0x00;
        ba[++i] = MessageType::INITIALIZATION;
        ba[++i] = init.hiddenSuspect;
        ba[++i] = init.hiddenWeapon;
        ba[++i] = init.hiddenRoom;
        ba[++i] = init.p1Card1;
        ba[++i] = init.p1Card2;
        ba[++i] = init.p1Card3;
        ba[++i] = init.p1Card4;
        ba[++i] = init.p1Card5;
        ba[++i] = init.p1Card6;
        ba[++i] = init.p2Card1;
        ba[++i] = init.p2Card2;
        ba[++i] = init.p2Card3;
        ba[++i] = init.p2Card4;
        ba[++i] = init.p2Card5;
        ba[++i] = init.p2Card6;
        ba[++i] = init.p3Card1;
        ba[++i] = init.p3Card2;
        ba[++i] = init.p3Card3;
        ba[++i] = init.p3Card4;
        ba[++i] = init.p3Card5;
        ba[++i] = init.p3Card6;
        ba[++i] = init.p4Card1;
        ba[++i] = init.p4Card2;
        ba[++i] = init.p4Card3;
        ba[++i] = init.p4Card4;
        ba[++i] = init.p5Card1;
        ba[++i] = init.p5Card2;
        ba[++i] = init.p5Card3;
        ba[++i] = init.p6Card1;
        ba[++i] = init.p6Card2;
        ba[++i] = init.p6Card3;
        ba[++i] = init.numConnected;
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

    QByteArray form_change_turn(ChangeTurn turn)
    {
        QByteArray ba;
        ba.resize(6);
        ba[0] = 0x06;
        ba[1] = 0x00;
        ba[2] = MessageType::CHANGE_TURN;
        ba[3] = turn.playerSource;
        ba[4] = turn.activePlayer;
        ba[5] = turn.gamePhase;
        return ba;
    }

    // Use DerivedClass * c = static_cast<DerivedClass>(baseClassPointer) to retrieve the derived class
    // once you've checked baseClassPointer->messageType.
    Action * parse_message(QByteArray ba)
    {
        int messageLength = ba[0] + 16 * ba[1];
        if (messageLength < 3)
        {
            return NULL;
        }
        MessageType messageType = (MessageType)(int)ba[2];

        switch(messageType) // No 'break' means all cases continue to default.
        {
        case MessageType::MOVEMENT :
            if (messageLength < 6)
            {
                return NULL;
            }
            return new Movement((PlayerEnum)(int)ba[3], (LocationTypeEnum)(int)ba[4], (LocationEnum)(int)ba[5]);
        case MessageType::SUGGESTION :
            if (messageLength < 7)
            {
                return NULL;
            }
            return new Suggestion((PlayerEnum)(int)ba[3], (CardEnum)(int)ba[4], (CardEnum)(int)ba[5], (CardEnum)(int)ba[6]);
        case MessageType::ACCUSATION :
            if (messageLength < 7)
            {
                return NULL;
            }
            return new Accusation((PlayerEnum)(int)ba[3], (CardEnum)(int)ba[4], (CardEnum)(int)ba[5], (CardEnum)(int)ba[6]);
        case MessageType::REFUTATION :
            if (messageLength < 6)
            {
                return NULL;
            }
            return new Refutation((PlayerEnum)(int)ba[3], (PlayerEnum)(int)ba[4], (CardEnum)(int)ba[5]);
        case MessageType::INITIALIZATION :
        {
            // This one is MUCH more aggressive. This actually *sets* all the values on the board.
            if (messageLength < 35)
            {
                return NULL;
            }
            Initialization* init = new Initialization();
            int i = 2;
            init->hiddenSuspect = (CardEnum) ba.data()[++i];
            init->hiddenWeapon = (CardEnum) ba.data()[++i];
            init->hiddenRoom = (CardEnum) ba.data()[++i];
            init->p1Card1 = (CardEnum) ba.data()[++i];
            init->p1Card2 = (CardEnum) ba.data()[++i];
            init->p1Card3 = (CardEnum) ba.data()[++i];
            init->p1Card4 = (CardEnum) ba.data()[++i];
            init->p1Card5 = (CardEnum) ba.data()[++i];
            init->p1Card6 = (CardEnum) ba.data()[++i];
            init->p2Card1 = (CardEnum) ba.data()[++i];
            init->p2Card2 = (CardEnum) ba.data()[++i];
            init->p2Card3 = (CardEnum) ba.data()[++i];
            init->p2Card4 = (CardEnum) ba.data()[++i];
            init->p2Card5 = (CardEnum) ba.data()[++i];
            init->p2Card6 = (CardEnum) ba.data()[++i];
            init->p3Card1 = (CardEnum) ba.data()[++i];
            init->p3Card2 = (CardEnum) ba.data()[++i];
            init->p3Card3 = (CardEnum) ba.data()[++i];
            init->p3Card4 = (CardEnum) ba.data()[++i];
            init->p3Card5 = (CardEnum) ba.data()[++i];
            init->p3Card6 = (CardEnum) ba.data()[++i];
            init->p4Card1 = (CardEnum) ba.data()[++i];
            init->p4Card2 = (CardEnum) ba.data()[++i];
            init->p4Card3 = (CardEnum) ba.data()[++i];
            init->p4Card4 = (CardEnum) ba.data()[++i];
            init->p5Card1 = (CardEnum) ba.data()[++i];
            init->p5Card2 = (CardEnum) ba.data()[++i];
            init->p5Card3 = (CardEnum) ba.data()[++i];
            init->p6Card1 = (CardEnum) ba.data()[++i];
            init->p6Card2 = (CardEnum) ba.data()[++i];
            init->p6Card3 = (CardEnum) ba.data()[++i];
            init->numConnected = ba[++i];

            return init;
        }
        case MessageType::PLAYER_CONNECT :
            if (messageLength < 4)
            {
                return NULL;
            }
            return new PlayerConnect((PlayerEnum)(int)ba[3]);
        case MessageType::CHANGE_TURN :
            if (messageLength < 6)
            {
                return NULL;
            }
            return  new ChangeTurn((PlayerEnum)(int)ba[3], (PlayerEnum)(int)ba[4], (GamePhaseEnum)(int)ba[5]);
        default:
            return NULL;
        }
    }

    QList<QByteArray> splitMessages(QByteArray msg)
    {
        //list that stores separated messages
        QList<QByteArray> returnList;

        QByteArray bunchedArray = msg;

        while(bunchedArray.size() > 0)
        {
            int msgSize = bunchedArray.data()[0];

            if (msgSize < 4)
            {
                //too small
                break;
            }
            else if (msgSize > bunchedArray.size())
            {
                //message is incomplete
                break;
            }
            else
            {
                returnList.append(bunchedArray.left(msgSize));
                bunchedArray = bunchedArray.remove(0, msgSize);
            }
        }

        return returnList;
    }
}
