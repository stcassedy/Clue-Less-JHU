/**
  * @file Board.cpp
  */
#include "Board.h"
#include "WeaponCard.h"
#include "PlayerCard.h"
#include "RoomCard.h"
#include "Card.h"
#include "Player.h"
#include "BoardElement.h"
#include "Room.h"
#include "Hallway.h"

// -----------------------------------------------------------------------------
// Constructor:
Board* Board::m_instance = NULL;

// -----------------------------------------------------------------------------
// Constructor:
Board::Board()
{
    //builds the Card lookup map
    initializeCardLookup();
    initializePlayerLookup();
    initializeBoardElementLookup();
}

// -----------------------------------------------------------------------------
// Destructor:
Board::~Board()
{
    //Deletes pointers to Card objects and clears the map
    qDeleteAll(m_cardLookup);
    m_cardLookup.clear();

    //Deletes pointers to Player objects and clears the map
    qDeleteAll(m_playerLookup);
    m_playerLookup.clear();

    //Deletes pointers to BoardElement objects and clears the map
    qDeleteAll(m_boardElementLookup);
    m_boardElementLookup.clear();
}

// -----------------------------------------------------------------------------
// Public Functions:
Board* Board::makeInstance()
{
    //deletes instance if one exists
    if (m_instance != NULL)
    {
        delete m_instance;
        m_instance = NULL;
    }

    //creates a new instance
    m_instance = new Board();
    return m_instance;
}

void Board::destroyInstance()
{
    //deletes instance if one exists
    if (m_instance != NULL)
    {
        delete m_instance;
        m_instance = NULL;
    }
}

Board* Board::getInstance()
{
    //returns the board instance
    return m_instance;
}

Card* Board::getCard(CardEnum card)
{
    //returns a card from the lookup
    return m_cardLookup.value(card);
}

Player* Board::getPlayer(PlayerEnum player)
{
    //returns a player from the lookup
    return m_playerLookup.value(player);
}

BoardElement* Board::getBoardElement(LocationEnum loc)
{
    //returns a board element from the lookup
    return m_boardElementLookup.value(loc);
}

QList<Card*> Board::getAllCards()
{
    //returns all of the card objects in a list
    return m_cardLookup.values();
}

QList<Player*> Board::getAllPlayers()
{
    //returns all of the player objects in a list
    return m_playerLookup.values();
}

QList<BoardElement*> Board::getAllBoardElements()
{
    //returns all of the board element objects in a list
    return m_boardElementLookup.values();
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
    m_cardLookup[INVALID_CARD] =
            new PlayerCard(INVALID_CARD, "Invalid");
}

void Board::initializePlayerLookup()
{
    //maps all of the lookup keys to their respective values
    m_playerLookup[MISS_SCARLET] =
            new Player(MISS_SCARLET, HALLWAY_2);
    m_playerLookup[COL_MUSTARD] =
            new Player(COL_MUSTARD, HALLWAY_5);
    m_playerLookup[MRS_WHITE] =
            new Player(MRS_WHITE, HALLWAY_12);
    m_playerLookup[MR_GREEN] =
            new Player(MR_GREEN, HALLWAY_11);
    m_playerLookup[MRS_PEACOCK] =
            new Player(MRS_PEACOCK, HALLWAY_8);
    m_playerLookup[PROF_PLUM] =
            new Player(PROF_PLUM, HALLWAY_3);
}

void Board::initializeBoardElementLookup()
{
    //maps all of the lookup keys to their respective values
    m_boardElementLookup[STUDY] =
            new Room(STUDY);
    m_boardElementLookup[LOUNGE] =
            new Room(LOUNGE);
    m_boardElementLookup[BILLIARD_ROOM] =
            new Room(BILLIARD_ROOM);
    m_boardElementLookup[LIBRARY] =
            new Room(LIBRARY);
    m_boardElementLookup[HALL] =
            new Room(HALL);
    m_boardElementLookup[DINING_ROOM] =
            new Room(DINING_ROOM);
    m_boardElementLookup[CONSERVATORY] =
            new Room(CONSERVATORY);
    m_boardElementLookup[BALLROOM] =
            new Room(BALLROOM);
    m_boardElementLookup[KITCHEN] =
            new Room(KITCHEN);
    m_boardElementLookup[HALLWAY_1] =
            new Hallway(HALLWAY_1);
    m_boardElementLookup[HALLWAY_2] =
            new Hallway(HALLWAY_2);
    m_boardElementLookup[HALLWAY_3] =
            new Hallway(HALLWAY_3);
    m_boardElementLookup[HALLWAY_4] =
            new Hallway(HALLWAY_4);
    m_boardElementLookup[HALLWAY_5] =
            new Hallway(HALLWAY_5);
    m_boardElementLookup[HALLWAY_6] =
            new Hallway(HALLWAY_6);
    m_boardElementLookup[HALLWAY_7] =
            new Hallway(HALLWAY_7);
    m_boardElementLookup[HALLWAY_8] =
            new Hallway(HALLWAY_8);
    m_boardElementLookup[HALLWAY_9] =
            new Hallway(HALLWAY_9);
    m_boardElementLookup[HALLWAY_10] =
            new Hallway(HALLWAY_10);
    m_boardElementLookup[HALLWAY_11] =
            new Hallway(HALLWAY_11);
    m_boardElementLookup[HALLWAY_12] =
            new Hallway(HALLWAY_12);
}

Player* Board::getPlayerForCard(PlayerCard* card)
{
    //gets the card enum
    CardEnum cardEnum = card->getCardIdentifier();

    //determines the player
    if (cardEnum == SCARLET_CARD)
    {
        return getPlayer(MISS_SCARLET);
    }
    else if (cardEnum == MUSTARD_CARD)
    {
        return getPlayer(COL_MUSTARD);
    }
    else if (cardEnum == WHITE_CARD)
    {
        return getPlayer(MRS_WHITE);
    }
    else if (cardEnum == GREEN_CARD)
    {
        return getPlayer(MR_GREEN);
    }
    else if (cardEnum == PEACOCK_CARD)
    {
        return getPlayer(MRS_PEACOCK);
    }
    else
    {
        return getPlayer(PROF_PLUM);
    }
}

Room* Board::getRoomForCard(RoomCard* card)
{
    //gets the card enum
    CardEnum cardEnum = card->getCardIdentifier();

    //determines the room
    if (cardEnum == KITCHEN_CARD)
    {
        return dynamic_cast<Room*>(getBoardElement(KITCHEN));
    }
    else if (cardEnum == BALLROOM_CARD)
    {
        return dynamic_cast<Room*>(getBoardElement(BALLROOM));
    }
    else if (cardEnum == CONSERVATORY_CARD)
    {
        return dynamic_cast<Room*>(getBoardElement(CONSERVATORY));
    }
    else if (cardEnum == DINING_ROOM_CARD)
    {
        return dynamic_cast<Room*>(getBoardElement(DINING_ROOM));
    }
    else if (cardEnum == BILLIARD_ROOM_CARD)
    {
        return dynamic_cast<Room*>(getBoardElement(BILLIARD_ROOM));
    }
    else if (cardEnum == LIBRARY_CARD)
    {
        return dynamic_cast<Room*>(getBoardElement(LIBRARY));
    }
    else if (cardEnum == LOUNGE_CARD)
    {
        return dynamic_cast<Room*>(getBoardElement(LOUNGE));
    }
    else if (cardEnum == HALL_CARD)
    {
        return dynamic_cast<Room*>(getBoardElement(HALL));
    }
    else
    {
        return dynamic_cast<Room*>(getBoardElement(STUDY));
    }
}

QString Board::getPlayerStringFromEnum(PlayerEnum pEnum)
{
    //determines string based on current player enum
    QString currentPlayerString;
    if (pEnum == MISS_SCARLET)
    {
        currentPlayerString = QString("Miss Scarlet");
    }
    else if (pEnum == COL_MUSTARD)
    {
        currentPlayerString = QString("Col. Mustard");
    }
    else if (pEnum == MRS_WHITE)
    {
        currentPlayerString = QString("Mrs. White");
    }
    else if (pEnum == MR_GREEN)
    {
        currentPlayerString = QString("Mr. Green");
    }
    else if (pEnum == MRS_PEACOCK)
    {
        currentPlayerString = QString("Mrs. Peacock");
    }
    else
    {
        currentPlayerString = QString("Prof. Plum");
    }

    return currentPlayerString;
}
