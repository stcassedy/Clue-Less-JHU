/**
  * @file ServerWindow.cpp
  */
#include "Board.h"
#include "WeaponCard.h"
#include "PlayerCard.h"
#include "RoomCard.h"

// -----------------------------------------------------------------------------
// Constructor:
Board::Board()
{
    //builds the Card lookup map
    initializeCardLookup();
}

// -----------------------------------------------------------------------------
// Destructor:
Board::~Board()
{
    //Deletes pointers to Card objects and clears the map
    qDeleteAll(m_cardLookup);
    m_cardLookup.clear();
}

// -----------------------------------------------------------------------------
// Public Functions:
Board* Board::getInstance()
{
    return m_instance;
}

Card* Board::getCard(CardEnum card)
{
    return m_cardLookup.value(card);
}

// -----------------------------------------------------------------------------
// Private Functions:
void Board::initializeCardLookup()
{
    m_cardLookup[CANDLESTICK_CARD] =
            new WeaponCard(CANDLESTICK_CARD, "Candlestick");
    m_cardLookup[KNIFE_CARD] =
            new WeaponCard(KNIFE_CARD, "Knife");
    m_cardLookup[LEAD_PIPE_CARD] =
            new WeaponCard(LEAD_PIPE_CARD, "Lead Pipe");
    m_cardLookup[REVOLVER_CARD] =
            new WeaponCard(REVOLVER_CARD, "Revolver");
    m_cardLookup[ROPE_CARD] =
            new WeaponCard(ROPE_CARD, "Rope");
    m_cardLookup[WRENCH_CARD] =
            new WeaponCard(WRENCH_CARD, "Wrench");
    m_cardLookup[SCARLET_CARD] =
            new WeaponCard(SCARLET_CARD, "Miss Scarlet");
    m_cardLookup[MUSTARD_CARD] =
            new WeaponCard(MUSTARD_CARD, "Colonel Mustard");
    m_cardLookup[WHITE_CARD] =
            new WeaponCard(WHITE_CARD, "Mrs. White");
    m_cardLookup[GREEN_CARD] =
            new WeaponCard(GREEN_CARD, "Mr. Green");
    m_cardLookup[PEACOCK_CARD] =
            new WeaponCard(PEACOCK_CARD, "Mrs. Peacock");
    m_cardLookup[PLUM_CARD] =
            new WeaponCard(PLUM_CARD, "Professor Plum");
    m_cardLookup[KITCHEN_CARD] =
            new WeaponCard(KITCHEN_CARD, "Kitchen");
    m_cardLookup[BALLROOM_CARD] =
            new WeaponCard(BALLROOM_CARD, "Ballroom");
    m_cardLookup[CONSERVATORY_CARD] =
            new WeaponCard(CONSERVATORY_CARD, "Conservatory");
    m_cardLookup[DINING_ROOM_CARD] =
            new WeaponCard(DINING_ROOM_CARD, "Dining Room");
    m_cardLookup[BILLIARD_ROOM_CARD] =
            new WeaponCard(BILLIARD_ROOM_CARD, "Billiard Room");
    m_cardLookup[LIBRARY_CARD] =
            new WeaponCard(LIBRARY_CARD, "Library");
    m_cardLookup[LOUNGE_CARD] =
            new WeaponCard(LOUNGE_CARD, "Lounge");
    m_cardLookup[HALL_CARD] =
            new WeaponCard(HALL_CARD, "Hall");
    m_cardLookup[STUDY_CARD] =
            new WeaponCard(STUDY_CARD, "Study");
}
