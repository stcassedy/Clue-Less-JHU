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

//---------------------------------------------------------------
//Static Variables:
ClientManager ClientManager::m_instance;

//---------------------------------------------------------------
//Constructor:
ClientManager::ClientManager()
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
    return &m_instance;
}

void ClientManager::movePlayer(BoardElement* destination)
{
    //gets the current player object
    Player* player = Board::getInstance()->getPlayer(m_currentPlayer);
    player->move(destination);

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
