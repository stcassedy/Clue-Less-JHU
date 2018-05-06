#include "ClientManager.h"

#include "BoardEnums.h"
#include "BoardElement.h"
#include "Envelope.h"
#include "Card.h"
#include "Hand.h"
#include "PlayerCard.h"
#include "RoomCard.h"
#include "WeaponCard.h"
#include "Player.h"
#include "Board.h"
#include "ClientWindow.h"
#include "ServerProtocol.h"
#include "Connection.h"

#include <QDebug>

//---------------------------------------------------------------
//Static Variables:
ClientManager ClientManager::m_instance;

//---------------------------------------------------------------
//Constructor:
ClientManager::ClientManager() :
    m_currentPlayer(MISS_SCARLET),
    m_currentPlayerTurn(MISS_SCARLET),
    m_currentPhase(MOVE),
    m_numberOfPlayers(4),
    m_clientWindow(NULL),
    m_serverConnection(true)
{
    //TODO: game phase should start in NOT_JOINED phase
    //TODO: number of players should not start at 3
    //TODO: server connection should not start as true
}

//---------------------------------------------------------------
//Constructor:
ClientManager::~ClientManager()
{
    //deletes tcp connection
    if (m_tcpConnection != NULL)
    {
        delete m_tcpConnection;
    }
}

//---------------------------------------------------------------
//Public Functions:
ClientManager* ClientManager::getInstance()
{
    //returns a pointer to the ClientManager instance
    return &m_instance;
}

void ClientManager::setClientWindow(ClientWindow* clientWindow)
{
    //sets the pointer to the client window
    m_clientWindow = clientWindow;
}

ClientWindow* ClientManager::getClientWindow()
{
    //returns a pointer to the client window
    return m_clientWindow;
}

void ClientManager::startGame()
{
    //tell server to start the game!
    qDebug() << "Start Game!";
}

void ClientManager::movePlayer(BoardElement* destination)
{
    //gets the current player object
    Player* player = Board::getInstance()->getPlayer(m_currentPlayer);
    player->move(destination);
    m_clientWindow->updateUI();

    //NOTE: Notify Server of the move player action
    //we should probably wait to move the player until we get a reponse from
    //the server
}

bool ClientManager::makeSuggestion(RoomCard* room, PlayerCard* player,
                                   WeaponCard* weapon)
{
    //NOTE: Win game logic belongs more in the server manager than client
    //we should just be sending the suggestion information to the server

    bool win_game = false;

    //creates suggestion envelope
    Envelope suggestionEnv;
    suggestionEnv.setRoomCard(room);
    suggestionEnv.setPlayerCard(player);
    suggestionEnv.setWeaponCard(weapon);

    qDebug() << "Accused Room: " << room->getCardName();
    qDebug() << "Accused Player: " << player->getCardName();
    qDebug() << "Accused Weapon: " << weapon->getCardName();

    //gets the hidden envelope
    Envelope* env = Board::getInstance()->getHiddenEnvelope();

    //compares suggestion to hidden envelope
    if(env->isAccusationCorrect(&suggestionEnv))
    {
        win_game = true;
    }
    return win_game;
}

void ClientManager::refuteSuggestion(Card* card)
{
    qDebug() << "Refute Card: " << card->getCardName();
}

bool ClientManager::makeAccusation(RoomCard *room, PlayerCard *player,
                                   WeaponCard *weapon)
{
    //NOTE: Win game logic belongs more in the server manager than client
    //we should just be sending the accusation information to the server

    bool win_game = false;

    //creates accusation envelope
    Envelope accusationEnv;
    accusationEnv.setRoomCard(room);
    accusationEnv.setPlayerCard(player);
    accusationEnv.setWeaponCard(weapon);

    qDebug() << "Accused Room: " << room->getCardName();
    qDebug() << "Accused Player: " << player->getCardName();
    qDebug() << "Accused Weapon: " << weapon->getCardName();

    //gets the hidden envelope
    Envelope* env = Board::getInstance()->getHiddenEnvelope();

    //compares suggestion to hidden envelope
    if(env->isAccusationCorrect(&accusationEnv))
    {
        win_game = true;
    }
    return win_game;
}

void ClientManager::endTurn()
{
    //TODO: Notify server the player ends their turn without an accusation
    qDebug() << "End Turn.";
}

void ClientManager::connectToServer()
{
    QString host = "placeholder";
    int port = 12321;

    //deletes the old connection
    if (m_tcpConnection != NULL)
    {
        delete m_tcpConnection;
        m_tcpConnection = NULL;
    }

    //creates a new connection and attempts to open the connection
    m_tcpConnection = new Connection(host, port);
    m_serverConnection = m_tcpConnection->openConnection();
}

Player* ClientManager::getCurrentPlayer()
{
    //returns the client player
    Player* player = Board::getInstance()->getPlayer(m_currentPlayer);
    return player;
}

Player* ClientManager::getCurrentPlayerTurn()
{
    //returns the player whose turn it is
    Player* player = Board::getInstance()->getPlayer(m_currentPlayerTurn);
    return player;
}

GamePhaseEnum ClientManager::getCurrentGamePhase()
{
    //returns the current game phase
    return m_currentPhase;
}

int ClientManager::getNumberOfPlayers()
{
    //returns the current number of players
    return m_numberOfPlayers;
}

bool ClientManager::serverConnected()
{
    //returns the server connection status
    return m_serverConnection;
}

void ClientManager::processServerAction(protocol::Action* act)
{
    //Determine message type
    protocol::MessageType type = act->messageType;

    //process message based on type
    if (type == protocol::MOVEMENT)
    {
        protocol::Movement* mov =
                reinterpret_cast<protocol::Movement*>(act);
        processMovement(mov);
    }
    else if (type == protocol::SUGGESTION)
    {
        protocol::Suggestion* sug =
                reinterpret_cast<protocol::Suggestion*>(act);
        processSuggestion(sug);
    }
    else if (type == protocol::ACCUSATION)
    {
        protocol::Accusation* acc =
                reinterpret_cast<protocol::Accusation*>(act);
        processAccusation(acc);
    }
    else if (type == protocol::REFUTATION)
    {
        protocol::Refutation* ref =
                reinterpret_cast<protocol::Refutation*>(act);
        processRefutation(ref);
    }
    else if (type == protocol::INITIALIZATION)
    {
        protocol::Initialization* init =
                reinterpret_cast<protocol::Initialization*>(act);
        processInitialization(init);
    }
    else if (type == protocol::PLAYER_CONNECT)
    {
        protocol::PlayerConnect* con =
                reinterpret_cast<protocol::PlayerConnect*>(act);
        processPlayerConnect(con);
    }
}

void ClientManager::processMovement(protocol::Movement* mov)
{

}

void ClientManager::processSuggestion(protocol::Suggestion* sug)
{

}

void ClientManager::processAccusation(protocol::Accusation* acc)
{

}

void ClientManager::processRefutation(protocol::Refutation* ref)
{

}

void ClientManager::processInitialization(protocol::Initialization* init)
{

}

void ClientManager::processPlayerConnect(protocol::PlayerConnect* con)
{

}
