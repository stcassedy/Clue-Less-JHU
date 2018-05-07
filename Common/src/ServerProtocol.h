#ifndef SERVERPROTOCOL_H
#define SERVERPROTOCOL_H

#include <QByteArray>
#include <BoardEnums.h>
#include <Board.h>
#include <Card.h>
#include <Player.h>

namespace protocol
{
enum MessageType
{
    MOVEMENT = 0x10,
    SUGGESTION,
    ACCUSATION,
    REFUTATION,
    INITIALIZATION = 0x20,
    PLAYER_CONNECT
};

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
    Suggestion(PlayerEnum playerSource, CardEnum playerSuggested, CardEnum location, CardEnum weapon)
        : Action(playerSource, MessageType::SUGGESTION), playerSuggested(playerSuggested), location(location), weapon(weapon) {}
    CardEnum playerSuggested;
    CardEnum location;
    CardEnum weapon;
};

class Accusation : public Action
{
public:
    Accusation(PlayerEnum playerSource, CardEnum playerAccused, CardEnum location, CardEnum weapon)
        : Action(playerSource, MessageType::ACCUSATION), playerAccused(playerAccused), location(location), weapon(weapon) {}
    CardEnum playerAccused;
    CardEnum location;
    CardEnum weapon;
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

    QByteArray form_movement(Movement movement);
    QByteArray form_suggestion(Suggestion suggestion);
    QByteArray form_accusation(Accusation accusation);
    QByteArray form_refutation(Refutation refutation);
    QByteArray form_initialization(Initialization init);
    QByteArray form_player_connect(PlayerConnect conn);
    Action * parse_message(QByteArray ba);

}

#endif // SERVERPROTOCOL_H
