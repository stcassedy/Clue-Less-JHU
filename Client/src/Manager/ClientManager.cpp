#include "ClientManager.h"

#include "BoardEnums.h"
#include "BoardElement.h"
#include "Envelope.h"
#include "Card.h"


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

void makeSuggestion()
{

}
