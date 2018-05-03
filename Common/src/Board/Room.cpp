/**
  * @file Room.h
  */
#include "Room.h"

//Constructor:
Room::Room(LocationEnum loc, QList<LocationEnum> connectedLocList) :
    BoardElement(ROOM, loc)
{

}

//Deconstructor
Room::~Room() {

}

bool Room::openForNewPlayer() {
	//No limit to number of players in the room (asides from max num of players)
	return true;
}
