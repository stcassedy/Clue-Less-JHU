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
void ClientManager::movePlayer(BoardElement* destination, BoardElement* location)
{
    //Note: if checks can be removed, the UI will enforce these checks
    if(destination->openForNewPlayer() == true && location->isBoardElementConnected(destination->getBoardElementEnum()) == true)
    {
        destination->addPlayer(currentPlayer);
        location->removePlayer(currentPlayer);
    }
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
