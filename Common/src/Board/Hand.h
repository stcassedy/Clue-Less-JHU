/**
  * @file Hand.h
  */
#ifndef HAND_H
#define HAND_H

#include "BoardEnums.h"
#include <QList>

//Forward Declaration
class Card;
class WeaponCard;
class RoomCard;
class PlayerCard;

/**
 * @brief The Hand class represents a player's hand of cards
 */
class Hand
{
public:
    /**
     * @brief Hand Explicit Constructor
     */
    explicit Hand();

    /**
     * @brief ~Hand Destructor
     */
    ~Hand();

    /**
     * @brief addCard adds a card to the hand
     * @param card Card*
     */
    void addCard(Card* card);

    /**
     * @brief containsCard checks if the hand is holding the card
     * @param card Card*
     * @return bool true if the card is in the hand, false otherwise
     */
    bool containsCard(Card* card);

    /**
     * @brief getCardList gets the card in the hand
     * @return QListCard<Card*>
     */
    QList<Card*> getCardList();

    /**
     * @brief getWeaponCardList gets the weapon cards in the hand
     * @return QListCard<Card*>
     */
    QList<WeaponCard*> getWeaponCardList();

    /**
     * @brief getRoomCardList gets the room cards in the hand
     * @return QListCard<Card*>
     */
    QList<RoomCard*> getRoomCardList();

    /**
     * @brief getPlayerCardList gets the player cards in the hand
     * @return QListCard<Card*>
     */
    QList<PlayerCard*> getPlayerCardList();

private:
    //Member Variables
    QList<CardEnum> m_cardList;
};

#endif // HAND_H
