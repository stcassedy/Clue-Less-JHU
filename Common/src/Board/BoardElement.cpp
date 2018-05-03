#include "BoardElement.h"
#include "QList"


// -----------------------------------------------------------------------------
//Constructor
BoardElement::BoardElement(LocationTypeEnum typ, LocationEnum loc)
{
    type = typ;
    location = loc;
    if(loc == STUDY)
    {
        connected.append(HALLWAY_1);
        connected.append(HALLWAY_3);
        connected.append(KITCHEN);
    }
    else if(loc == HALLWAY_1)
    {
        connected.append(STUDY);
        connected.append(HALL);
    }
    else if(loc == HALL)
    {
         connected.append(HALLWAY_1);
         connected.append(HALLWAY_2);
         connected.append(HALLWAY_4);
    }
    else if(loc == HALLWAY_2)
    {
         connected.append(HALL);
         connected.append(LOUNGE);
    }
    else if(loc == LOUNGE)
    {
         connected.append(HALLWAY_5);
         connected.append(HALLWAY_2);
         connected.append(CONSERVATORY);
    }
    else if(loc == HALLWAY_3)
    {
         connected.append(STUDY);
         connected.append(LIBRARY);
    }
    else if(loc == HALLWAY_4)
    {
         connected.append(BILLIARD_ROOM);
         connected.append(HALL);
    }
    else if(loc == HALLWAY_5)
    {
         connected.append(LOUNGE);
         connected.append(DINING_ROOM);
    }
    else if(loc == LIBRARY)
    {
         connected.append(HALLWAY_3);
         connected.append(HALLWAY_6);
         connected.append(HALLWAY_8);
    }
    else if(loc == HALLWAY_6)
    {
         connected.append(LIBRARY);
         connected.append(BILLIARD_ROOM);
    }
    else if(loc == BILLIARD_ROOM)
    {
         connected.append(HALLWAY_4);
         connected.append(HALLWAY_6);
         connected.append(HALLWAY_7);
         connected.append(HALLWAY_9);
    }
    else if(loc == HALLWAY_7)
    {
         connected.append(BILLIARD_ROOM);
         connected.append(DINING_ROOM);
    }
    else if(loc == DINING_ROOM)
    {
         connected.append(HALLWAY_5);
         connected.append(HALLWAY_7);
         connected.append(HALLWAY_10);
    }
    else if(loc == HALLWAY_8)
    {
         connected.append(LIBRARY);
         connected.append(CONSERVATORY);
    }
    else if(loc == HALLWAY_9)
    {
         connected.append(BILLIARD_ROOM);
         connected.append(BALLROOM);
    }
    else if(loc == HALLWAY_10)
    {
         connected.append(DINING_ROOM);
         connected.append(KITCHEN);
    }
    else if(loc == CONSERVATORY)
    {
         connected.append(HALLWAY_8);
         connected.append(HALLWAY_11);
         connected.append(LOUNGE);
    }
    else if(loc == HALLWAY_11)
    {
         connected.append(CONSERVATORY);
         connected.append(BALLROOM);
    }
    else if(loc == BALLROOM)
    {
         connected.append(HALLWAY_11);
         connected.append(HALLWAY_12);
    }
    else if(loc == HALLWAY_12)
    {
         connected.append(BALLROOM);
         connected.append(KITCHEN);
    }
    else if(loc == KITCHEN)
    {
         connected.append(HALLWAY_10);
         connected.append(HALLWAY_12);
         connected.append(STUDY);
    }

}

// -----------------------------------------------------------------------------
//Destructor
BoardElement::~BoardElement()
{

}

// -----------------------------------------------------------------------------
//Public Functions

LocationTypeEnum BoardElement::getBoardElementType()
{
    return type;
}

LocationEnum BoardElement::getBoardElementEnum()
{
    return location;
}

QList<LocationEnum> BoardElement::getConnectedElements()
{
    return connected;
}

bool BoardElement::isBoardElementConnected(LocationEnum destination)
{
    return connected.contains(destination);
}

bool BoardElement::isSpaceAvailable(LocationEnum)
{
    bool available = false;
    if(type == ROOM || (type == HALLWAY && players.isEmpty() == true))
    {
        available = true;
    }
    return available;
}

void BoardElement::addPlayer(PlayerEnum player)
{
    players.append(player);

}

void BoardElement::removePlayer(PlayerEnum player)
{
    players.removeAll(player);
}

