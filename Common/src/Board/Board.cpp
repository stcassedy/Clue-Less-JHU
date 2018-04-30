/**
  * @file Board.cpp
  */
#include "Board.h"
#include "WeaponCard.h"
#include "PlayerCard.h"
#include "RoomCard.h"

// -----------------------------------------------------------------------------
// Constructor:
Board Board::m_instance;

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
    //returns the board instance
    return &m_instance;
}

Card* Board::getCard(CardEnum card)
{
    //returns a card from the lookup
    return m_cardLookup.value(card);
}

Envelope* Board::getHiddenEnvelope()
{
    //returns the hidden envelope
    return &m_envelope;
}

// -----------------------------------------------------------------------------
// Private Functions:
void Board::initializeCardLookup()
{
    //maps all of the lookup keys to their respective values
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
            new PlayerCard(SCARLET_CARD, "Miss Scarlet");
    m_cardLookup[MUSTARD_CARD] =
            new PlayerCard(MUSTARD_CARD, "Colonel Mustard");
    m_cardLookup[WHITE_CARD] =
            new PlayerCard(WHITE_CARD, "Mrs. White");
    m_cardLookup[GREEN_CARD] =
            new PlayerCard(GREEN_CARD, "Mr. Green");
    m_cardLookup[PEACOCK_CARD] =
            new PlayerCard(PEACOCK_CARD, "Mrs. Peacock");
    m_cardLookup[PLUM_CARD] =
            new PlayerCard(PLUM_CARD, "Professor Plum");
    m_cardLookup[KITCHEN_CARD] =
            new RoomCard(KITCHEN_CARD, "Kitchen");
    m_cardLookup[BALLROOM_CARD] =
            new RoomCard(BALLROOM_CARD, "Ballroom");
    m_cardLookup[CONSERVATORY_CARD] =
            new RoomCard(CONSERVATORY_CARD, "Conservatory");
    m_cardLookup[DINING_ROOM_CARD] =
            new RoomCard(DINING_ROOM_CARD, "Dining Room");
    m_cardLookup[BILLIARD_ROOM_CARD] =
            new RoomCard(BILLIARD_ROOM_CARD, "Billiard Room");
    m_cardLookup[LIBRARY_CARD] =
            new RoomCard(LIBRARY_CARD, "Library");
    m_cardLookup[LOUNGE_CARD] =
            new RoomCard(LOUNGE_CARD, "Lounge");
    m_cardLookup[HALL_CARD] =
            new RoomCard(HALL_CARD, "Hall");
    m_cardLookup[STUDY_CARD] =
            new RoomCard(STUDY_CARD, "Study");
}
