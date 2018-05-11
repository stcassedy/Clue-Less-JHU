#ifndef SERVERPROTOCOL_H
#define SERVERPROTOCOL_H

#include <QByteArray>
#include <BoardEnums.h>
#include <GamePhaseEnums.h>
#include <Board.h>
#include <Card.h>
#include <Player.h>
#include <QList>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>

using namespace std;

namespace protocol
{
enum MessageType
{
    MOVEMENT = 0x10,
    SUGGESTION,
    ACCUSATION,
    REFUTATION,
    INITIALIZATION = 0x20,
    PLAYER_CONNECT,
    CHANGE_TURN
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
    Initialization() : Action(PlayerEnum::SERVER, MessageType::INITIALIZATION){}
    // Constructor would be too complicated if it took parameters. Instead, construct empty and add parameters.
    CardEnum hiddenSuspect;
    CardEnum hiddenWeapon;
    CardEnum hiddenRoom;
    CardEnum p1Card1;
    CardEnum p1Card2;
    CardEnum p1Card3;
    CardEnum p1Card4;
    CardEnum p1Card5;
    CardEnum p1Card6;
    CardEnum p2Card1;
    CardEnum p2Card2;
    CardEnum p2Card3;
    CardEnum p2Card4;
    CardEnum p2Card5;
    CardEnum p2Card6;
    CardEnum p3Card1;
    CardEnum p3Card2;
    CardEnum p3Card3;
    CardEnum p3Card4;
    CardEnum p3Card5;
    CardEnum p3Card6;
    CardEnum p4Card1;
    CardEnum p4Card2;
    CardEnum p4Card3;
    CardEnum p4Card4;
    CardEnum p5Card1;
    CardEnum p5Card2;
    CardEnum p5Card3;
    CardEnum p6Card1;
    CardEnum p6Card2;
    CardEnum p6Card3;
    qint8 numConnected;
};

class PlayerConnect : public Action
{
public:
    PlayerConnect(PlayerEnum playerAssignment)
        : Action(PlayerEnum::SERVER, MessageType::PLAYER_CONNECT), playerAssignment(playerAssignment) {}
    PlayerEnum playerAssignment;
};

class ChangeTurn : public Action
{
public:
    // prevPlayer and nextPlayer can be the same.
    ChangeTurn(PlayerEnum playerSource, PlayerEnum activePlayer, GamePhaseEnum gamePhase)
        : Action(playerSource, MessageType::CHANGE_TURN), activePlayer(activePlayer), gamePhase(gamePhase) {}
    PlayerEnum activePlayer;
    GamePhaseEnum gamePhase;
};

    QByteArray form_movement(Movement movement);
    QByteArray form_suggestion(Suggestion suggestion);
    QByteArray form_accusation(Accusation accusation);
    QByteArray form_refutation(Refutation refutation);
    QByteArray form_initialization(Initialization init);
    QByteArray form_player_connect(PlayerConnect conn);
    QByteArray form_change_turn(ChangeTurn turn);
    Action * parse_message(QByteArray ba);
    QList<QByteArray> splitMessages(QByteArray msg);

}

#endif // SERVERPROTOCOL_H
