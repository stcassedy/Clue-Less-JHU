/**
  * @file PlayerCard.cpp
  */
#include "PlayerCard.h"

// -----------------------------------------------------------------------------
// Constructor:
PlayerCard::PlayerCard(CardEnum identifier, QString name) :
    Card(PLAYER_CARD, identifier, name)
{

}

// -----------------------------------------------------------------------------
// Destructor:
PlayerCard::~PlayerCard()
{

}
