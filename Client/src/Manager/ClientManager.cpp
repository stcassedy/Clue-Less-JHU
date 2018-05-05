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

//---------------------------------------------------------------
//Static Variables:
ClientManager ClientManager::m_instance;

//---------------------------------------------------------------
//Constructor:
ClientManager::ClientManager() :
    m_currentPlayer(MISS_SCARLET),
    m_currentPlayerTurn(false),
    m_currentPhase(GAME_LOBBY),
    m_numberOfPlayers(1),
    m_clientWindow(NULL)
{

}

//---------------------------------------------------------------
//Constructor:
ClientManager::~ClientManager()
{

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

    //gets the hidden envelope
    Envelope* env = Board::getInstance()->getHiddenEnvelope();

    //compares suggestion to hidden envelope
    if(env->isAccusationCorrect(&suggestionEnv))
    {
        win_game = true;
    }
    return win_game;
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

    //gets the hidden envelope
    Envelope* env = Board::getInstance()->getHiddenEnvelope();

    //compares suggestion to hidden envelope
    if(env->isAccusationCorrect(&accusationEnv))
    {
        win_game = true;
    }
    return win_game;
}

Player* ClientManager::getCurrentPlayer()
{
    //returns the client player
    Player* player = Board::getInstance()->getPlayer(m_currentPlayer);
    return player;
}

GamePhaseEnum ClientManager::getCurrentGamePhase()
{
    //returns the current game phase
    return m_currentPhase;
}
