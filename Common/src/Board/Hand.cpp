/**
  * @file Hand.cpp
  */
#include "Hand.h"
#include "Card.h"
#include "WeaponCard.h"
#include "RoomCard.h"
#include "PlayerCard.h"
#include "Board.h"

// -----------------------------------------------------------------------------
// Constructor:
Hand::Hand()
{

}

// -----------------------------------------------------------------------------
// Destructor:
Hand::~Hand()
{

}

// -----------------------------------------------------------------------------
// Public Functions:
void Hand::addCard(Card *card)
{
    m_cardList.append(card->getCardIdentifier());
}

bool Hand::containsCard(Card *card)
{
    return m_cardList.contains(card->getCardIdentifier());
}

QList<Card*> Hand::getCardList()
{
    //initializes the return list
    QList<Card*> returnList;

    //iterates through cards in hand
    for (int i = 0; i < m_cardList.size(); ++i)
    {
        //adds the card object to the return list
        CardEnum cEnum = m_cardList.at(i);
        Card* card = Board::getInstance()->getCard(cEnum);
        returnList.append(card);
    }

    //returns a list of all the cards in the hand
    return returnList;
}

QList<WeaponCard*> Hand::getWeaponCardList()
{
    //initializes the return list
    QList<WeaponCard*> returnList;

    //iterates through cards in hand
    for (int i = 0; i < m_cardList.size(); ++i)
    {
        //gets a card from the hand
        CardEnum cEnum = m_cardList.at(i);
        Card* card = Board::getInstance()->getCard(cEnum);

        //checks if the card is a weapon card
        if (card->getCardType() == WEAPON_CARD)
        {
            //adds the weapon card to the return list
            WeaponCard* wCard = dynamic_cast<WeaponCard*>(card);
            returnList.append(wCard);
        }
    }

    //returns all of the weapon cards in the hand
    return returnList;
}

QList<RoomCard*> Hand::getRoomCardList()
{
    //initializes the return list
    QList<RoomCard*> returnList;

    //iterates through cards in hand
    for (int i = 0; i < m_cardList.size(); ++i)
    {
        //gets a card from the hand
        CardEnum cEnum = m_cardList.at(i);
        Card* card = Board::getInstance()->getCard(cEnum);

        //checks if the card is a room card
        if (card->getCardType() == ROOM_CARD)
        {
            //adds the room card to the return list
            RoomCard* rCard = dynamic_cast<RoomCard*>(card);
            returnList.append(rCard);
        }
    }

    //returns all of the room cards in the hand
    return returnList;
}

QList<PlayerCard*> Hand::getPlayerCardList()
{
    //initializes the return list
    QList<PlayerCard*> returnList;

    //iterates through cards in hand
    for (int i = 0; i < m_cardList.size(); ++i)
    {
        //gets a card from the hand
        CardEnum cEnum = m_cardList.at(i);
        Card* card = Board::getInstance()->getCard(cEnum);

        //checks if the card is a player card
        if (card->getCardType() == PLAYER_CARD)
        {
            //adds the player card to the return list
            PlayerCard* pCard = dynamic_cast<PlayerCard*>(card);
            returnList.append(pCard);
        }
    }

    //returns all of the player cards in the hand
    return returnList;
}
