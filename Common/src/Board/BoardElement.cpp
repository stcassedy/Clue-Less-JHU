#include "BoardElement.h"
#include "QList"


// -----------------------------------------------------------------------------
//Constructor
BoardElement::BoardElement(LocationTypeEnum typ, LocationEnum loc)
{
    m_type = typ;
    m_location = loc;
    if(loc == STUDY)
    {
        m_connected.append(HALLWAY_1);
        m_connected.append(HALLWAY_3);
        m_connected.append(KITCHEN);
    }
    else if(loc == HALLWAY_1)
    {
        m_connected.append(STUDY);
        m_connected.append(HALL);
    }
    else if(loc == HALL)
    {
         m_connected.append(HALLWAY_1);
         m_connected.append(HALLWAY_2);
         m_connected.append(HALLWAY_4);
    }
    else if(loc == HALLWAY_2)
    {
         m_connected.append(HALL);
         m_connected.append(LOUNGE);
    }
    else if(loc == LOUNGE)
    {
         m_connected.append(HALLWAY_5);
         m_connected.append(HALLWAY_2);
         m_connected.append(CONSERVATORY);
    }
    else if(loc == HALLWAY_3)
    {
         m_connected.append(STUDY);
         m_connected.append(LIBRARY);
    }
    else if(loc == HALLWAY_4)
    {
         m_connected.append(BILLIARD_ROOM);
         m_connected.append(HALL);
    }
    else if(loc == HALLWAY_5)
    {
         m_connected.append(LOUNGE);
         m_connected.append(DINING_ROOM);
    }
    else if(loc == LIBRARY)
    {
         m_connected.append(HALLWAY_3);
         m_connected.append(HALLWAY_6);
         m_connected.append(HALLWAY_8);
    }
    else if(loc == HALLWAY_6)
    {
         m_connected.append(LIBRARY);
         m_connected.append(BILLIARD_ROOM);
    }
    else if(loc == BILLIARD_ROOM)
    {
         m_connected.append(HALLWAY_4);
         m_connected.append(HALLWAY_6);
         m_connected.append(HALLWAY_7);
         m_connected.append(HALLWAY_9);
    }
    else if(loc == HALLWAY_7)
    {
         m_connected.append(BILLIARD_ROOM);
         m_connected.append(DINING_ROOM);
    }
    else if(loc == DINING_ROOM)
    {
         m_connected.append(HALLWAY_5);
         m_connected.append(HALLWAY_7);
         m_connected.append(HALLWAY_10);
    }
    else if(loc == HALLWAY_8)
    {
         m_connected.append(LIBRARY);
         m_connected.append(CONSERVATORY);
    }
    else if(loc == HALLWAY_9)
    {
         m_connected.append(BILLIARD_ROOM);
         m_connected.append(BALLROOM);
    }
    else if(loc == HALLWAY_10)
    {
         m_connected.append(DINING_ROOM);
         m_connected.append(KITCHEN);
    }
    else if(loc == CONSERVATORY)
    {
         m_connected.append(HALLWAY_8);
         m_connected.append(HALLWAY_11);
         m_connected.append(LOUNGE);
    }
    else if(loc == HALLWAY_11)
    {
         m_connected.append(CONSERVATORY);
         m_connected.append(BALLROOM);
    }
    else if(loc == BALLROOM)
    {
         m_connected.append(HALLWAY_11);
         m_connected.append(HALLWAY_12);
    }
    else if(loc == HALLWAY_12)
    {
         m_connected.append(BALLROOM);
         m_connected.append(KITCHEN);
    }
    else if(loc == KITCHEN)
    {
         m_connected.append(HALLWAY_10);
         m_connected.append(HALLWAY_12);
         m_connected.append(STUDY);
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
    return m_type;
}

LocationEnum BoardElement::getBoardElementEnum()
{
    return m_location;
}

QList<LocationEnum> BoardElement::getConnectedElements()
{
    return m_connected;
}

bool BoardElement::isBoardElementConnected(LocationEnum destination)
{
    return m_connected.contains(destination);
}

bool BoardElement::isSpaceAvailable()
{
    bool available = false;
    if(m_type == ROOM || (m_type == HALLWAY && m_players.isEmpty() == true))
    {
        available = true;
    }
    return available;
}

void BoardElement::addPlayer(PlayerEnum player)
{
    m_players.append(player);

}

void BoardElement::removePlayer(PlayerEnum player)
{
    m_players.removeAll(player);
}

QList<PlayerEnum> BoardElement::playersInElement()
{
    return m_players;
}
