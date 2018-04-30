/**
  * @file Hallway.h
  */
#include "Hallway.h"


//Constructor:
Hallway::Hallway(LocationEnum loc, QList<LocationEnum> connectedLocList)
{
    BoardElement(HALLWAY, loc, connectedLocList);
}

//Deconstructor
Hallway::~Hallway() {

}

//Public functions
bool Hallway::openForNewPlayer() {
	bool newPlayedAllowed = false;
	//Only open to other players when totally empty
	if(getPlayers().isEmpty()) {
		newPlayedAllowed = true;
	}
	return newPlayedAllowed;
}
