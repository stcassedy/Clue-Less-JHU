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
    m_serverConnection(false)
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
    //Get current player info
    Player* player = Board::getInstance()->getPlayer(m_currentPlayer);

    qDebug() << "Player: " << player->getPlayerNum();
    qDebug() << "Destination Type: " << destination->getBoardElementType();
    qDebug() << "Destination: " << destination->getBoardElementEnum();

    //Form movement message to send to server
    protocol::Movement* move
            = new protocol::Movement(player->getPlayerNum(), destination->getBoardElementType(), destination->getBoardElementEnum());
    QByteArray moveMessage = protocol::form_movement(*move);

    //Send message through connection
    m_tcpConnection->send(moveMessage);
}

void ClientManager::makeSuggestion(RoomCard* room, PlayerCard* player,
                                   WeaponCard* weapon)
{
    //Get current player info
    Player* curPlayer = Board::getInstance()->getPlayer(m_currentPlayer);

    qDebug() << "Suggested Room: " << room->getCardName();
    qDebug() << "Suggested Player: " << player->getCardName();
    qDebug() << "Accused Weapon: " << weapon->getCardName();


    //Build up message to send to server
    protocol::Suggestion* suggestion =
            new protocol::Suggestion(curPlayer->getPlayerNum(), player->getCardIdentifier(), room->getCardIdentifier(), weapon->getCardIdentifier());
    QByteArray suggestionMessage = protocol::form_suggestion(*suggestion);

    //Send message through connection
    m_tcpConnection->send(suggestionMessage);
}

void ClientManager::refuteSuggestion(Card* card)
{
    //Get player info
    Player* curPlayer = Board::getInstance()->getPlayer(m_currentPlayer);

    //Get info for player's whos turn it is (suggesting player)
    Player* suggestingPlayer = Board::getInstance()->getPlayer(m_currentPlayerTurn);

    qDebug() << "Suggesting Player: " << suggestingPlayer->getPlayerNum();
    qDebug() << "Refuting Player: " << curPlayer->getPlayerNum();
    qDebug() << "Refute Card: " << card->getCardName();

    protocol::Refutation* refutation
            = new protocol::Refutation(curPlayer->getPlayerNum(), suggestingPlayer->getPlayerNum(), card->getCardIdentifier());
    QByteArray refutationMessage = protocol::form_refutation(*refutation);

    //Send message through connection
    m_tcpConnection->send(refutationMessage);
}

void ClientManager::makeAccusation(RoomCard *room, PlayerCard *player,
                                   WeaponCard *weapon)
{ 
    //Get player info
    Player* curPlayer = Board::getInstance()->getPlayer(m_currentPlayer);

    qDebug() << "Accusing Player: " << curPlayer->getPlayerNum();
    qDebug() << "Accused Room: " << room->getCardName();
    qDebug() << "Accused Player: " << player->getCardName();
    qDebug() << "Accused Weapon: " << weapon->getCardName();

    //Build up accusation message
    protocol::Accusation* accusation
            = new protocol::Accusation(curPlayer->getPlayerNum(), player->getCardIdentifier(), room->getCardIdentifier(), weapon->getCardIdentifier());
    QByteArray accusationMessage = protocol::form_accusation(*accusation);

    //Send message through connection
    m_tcpConnection->send(accusationMessage);
}

void ClientManager::endTurn()
{
    //Get player info
    Player* curPlayer = Board::getInstance()->getPlayer(m_currentPlayer);

    //TODO: Get next player
    Player* nextPlayer = Board::getInstance()->getPlayer(m_currentPlayer);

    qDebug() << "End Turn for Player " << curPlayer->getPlayerNum();
    qDebug() << "Transition to Player " << nextPlayer->getPlayerNum();

    //Build up the change turn message
    protocol::ChangeTurn* changeTurn
            = new protocol::ChangeTurn(curPlayer->getPlayerNum(), nextPlayer->getPlayerNum(), m_currentPhase);
    QByteArray changeTurnMessage = protocol::form_change_turn(*changeTurn);

    //Send message through connection
    m_tcpConnection->send(changeTurnMessage);

}

void ClientManager::connectToServer(QString host, int port)
{
    //deletes the old connection
    if (m_tcpConnection != NULL)
    {
        delete m_tcpConnection;
        m_tcpConnection = NULL;
    }

    qDebug() << "Host Address: " << host;
    qDebug() << "Port: " << QString::number(port);

    //creates a new connection and attempts to open the connection
    m_tcpConnection = new Connection(host, port);
    m_serverConnection = m_tcpConnection->openConnection();
    if (!m_serverConnection)
    {
        qDebug() << "Connection timed out";
    }
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
    //moves the player and updates the UI
    Player* player = Board::getInstance()->getPlayer(mov->playerSource);
    BoardElement* elem = Board::getInstance()->getBoardElement(mov->location);
    player->move(elem);
    m_clientWindow->updateUI();
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
