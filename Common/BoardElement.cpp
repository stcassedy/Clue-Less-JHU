#include "BoardElement.h"



BoardElement::BoardElement(BoardElementType boardElementType, HallwayName hallwayName, RoomName roomName)
	: boardElementType_(boardElementType), hallwayName_(hallwayName), roomName_(roomName)
{
}


BoardElement::~BoardElement()
{
}


// Returns the board element type.
BoardElementType BoardElement::get_element_type()
{
	return boardElementType_;
}


// Returns the room name.
RoomName BoardElement::get_room_name()
{
	return roomName_;
}


// Returns the Hallway name.
HallwayName BoardElement::get_hallway_name()
{
	return hallwayName_;
}

// Returns a boolean of whether otherElement is connected.
bool BoardElement::is_element_connected(BoardElement otherElement)
{
	if (otherElement.get_element_type() == BoardElementType::hallway)
	{
		auto search = connectedHallways_.find(otherElement);
		if (search != connectedHallways_.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		auto search = connectedRooms_.find(otherElement);
		if (search != connectedRooms_.end())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}