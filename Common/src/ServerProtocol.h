#ifndef SERVERPROTOCOL_H
#define SERVERPROTOCOL_H

#include <QByteArray>
#include <BoardEnums.h>
#include <Board.h>
#include <Card.h>
#include <Player.h>

namespace protocol
{
    class Action;
    class Movement;
    class Suggestion;
    class Accusation;
    class Refutation;
    class Initialization;
    class PlayerConnect;
    QByteArray form_movement(Movement movement);
    QByteArray form_suggestion(Suggestion suggestion);
    QByteArray form_accusation(Accusation accusation);
    QByteArray form_refutation(Refutation refutation);
    QByteArray form_initialization(Initialization init);
    QByteArray form_player_connect(PlayerConnect conn);
    Action * parse_message(QByteArray ba);

    enum MessageType
    {
        MOVEMENT = 0x10,
        SUGGESTION,
        ACCUSATION,
        REFUTATION,
        INITIALIZATION = 0x20,
        PLAYER_CONNECT
    };

}

#endif // SERVERPROTOCOL_H
