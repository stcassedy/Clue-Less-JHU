/**
  * @file Hallway.h
  */
#include "Hallway.h"
#include "Board.h"
#include "Player.h"

//Constructor:
Hallway::Hallway(LocationEnum loc) :
    BoardElement(HALLWAY, loc)
{

}

//Deconstructor
Hallway::~Hallway()
{

}

//Public functions
bool Hallway::openForNewPlayer() {
    //gets a list of the players
    QList<Player*> playerList = Board::getInstance()->getAllPlayers();

    //iterates through the players
    for (int i = 0; i < playerList.size(); ++i)
    {
        //gets a players current location enum
        BoardElement* bElem = playerList.at(i)->getCurrentLocation();
        LocationEnum location = bElem->getBoardElementEnum();

        //checks if a player is in this hallway
        if (location == getBoardElementEnum())
        {
            return false;
        }
    }

    //none of the players were in this hallway
    return true;
}
