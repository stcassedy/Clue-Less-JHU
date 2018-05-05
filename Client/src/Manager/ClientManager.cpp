#include "ClientManager.h"

#include "BoardEnums.h"
#include "BoardElement.h"
#include "Envelope.h"
#include "Card.h"
#include "Hand.h"

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
void ClientManager::movePlayer(BoardElement destination, BoardElement location)
{
    if(destination.isSpaceAvailable() == true && location.isBoardElementConnected(destination.getBoardElementEnum()) == true)
    {
        destination.addPlayer(currentPlayer);
        location.removePlayer(currentPlayer);
    }
}

bool ClientManager::makeSuggestion(CardEnum room, CardEnum player, CardEnum weapon, Envelope env)
{
    bool win_game = false;
    if(room == env.getRoomCard() && player == env.getPlayerCard() && weapon == env.getWeaponCard())
    {
        win_game = true;
    }
    return win_game;
}



bool ClientManager::makeAccusation(CardEnum room, CardEnum player, CardEnum weapon, Envelope env)
{
    bool win_game = false;
    if(room == env.getRoomCard() && player == env.getPlayerCard() && weapon == env.getWeaponCard())
    {
        win_game = true;
    }
    return win_game;
}
