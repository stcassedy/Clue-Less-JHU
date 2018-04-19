/**
  * @file RoomCard.cpp
  */
#include "RoomCard.h"

// -----------------------------------------------------------------------------
// Constructor:
RoomCard::RoomCard(CardEnum identifier, QString name) :
    Card(ROOM_CARD, identifier, name)
{

}

// -----------------------------------------------------------------------------
// Destructor:
RoomCard::~RoomCard()
{

}
