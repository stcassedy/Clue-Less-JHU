#include "BoardElement.h"
#include "QList"


// -----------------------------------------------------------------------------
//Constructor
BoardElement::BoardElement(LocationTypeEnum typ, LocationEnum loc, QList<LocationEnum> locId)
{
    type = typ;
    location = loc;
    locId = locId;
    occupied = false;

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

bool BoardElement::openForNewPlayer()
{
    return occupied;
}

void BoardElement::setOccupied(bool set)
{
    occupied = set;
}

bool BoardElement::isBoardElementConnected(LocationEnum destination)
{

    bool boolean = false;

    if((destination == 0 &&  (location ==  9 || location == 11 || location ==  8)) ||
       (destination == 1 &&  (location == 10 || location == 13 || location ==  6)) ||
       (destination == 2 &&  (location == 14 || location == 12 || location == 17 || location == 15)) ||
       (destination == 3 &&  (location == 11 || location == 14 || location == 16)) ||
       (destination == 4 &&  (location ==  9 || location == 10 || location == 12)) ||
       (destination == 5 &&  (location == 15 || location == 13 || location == 18)) ||
       (destination == 6 &&  (location == 16 || location == 19 || location ==  1)) ||
       (destination == 7 &&  (location == 19 || location == 20 || location == 17)) ||
       (destination == 8 &&  (location == 20 || location == 18 || location ==  0)) ||
       (destination == 9 &&  (location ==  0 || location ==  4)) ||
       (destination == 10 && (location ==  4 || location ==  1)) ||
       (destination == 11 && (location ==  3 || location ==  0)) ||
       (destination == 12 && (location ==  2 || location ==  4)) ||
       (destination == 13 && (location ==  1 || location ==  5)) ||
       (destination == 14 && (location ==  3 || location ==  2)) ||
       (destination == 15 && (location ==  2 || location ==  5)) ||
       (destination == 16 && (location ==  3 || location ==  6)) ||
       (destination == 17 && (location ==  2 || location ==  7)) ||
       (destination == 18 && (location ==  5 || location ==  8)) ||
       (destination == 19 && (location ==  6 || location ==  7)) ||
       (destination == 20 && (location ==  7 || location ==  8)))

    {
        boolean = true;
        return boolean;
    }

    return boolean;
}

