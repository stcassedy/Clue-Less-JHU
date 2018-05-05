/**
  * @file Envelope.cpp
  */
#include "Envelope.h"
#include "WeaponCard.h"
#include "RoomCard.h"
#include "PlayerCard.h"

// -----------------------------------------------------------------------------
// Constructor:
Envelope::Envelope()
{

}

// -----------------------------------------------------------------------------
// Destructor:
Envelope::~Envelope()
{

}

// -----------------------------------------------------------------------------
// Public Functions:
void Envelope::setWeaponCard(WeaponCard* card)
{
    //sets the hidden weapon card
    m_weapon = card->getCardIdentifier();
}

void Envelope::setRoomCard(RoomCard* card)
{
    //sets the hidden room card
    m_room = card->getCardIdentifier();
}

void Envelope::setPlayerCard(PlayerCard* card)
{
    //sets the hidden player card
    m_player = card->getCardIdentifier();
}

int Envelope::getPlayerCard()
{
    return m_player;
}

int Envelope::getRoomCard()
{
    return m_room;
}

int Envelope::getWeaponCard()
{
    return m_weapon;
}

bool Envelope::isAccusationCorrect(Envelope* env)
{
    //checks if all of the cards in the accusation match
    return (m_weapon == env->m_weapon) &&
            (m_room == env->m_room) &&
            (m_player = env->m_player);
}
