/**
  * @file RoomCard.h
  */
#ifndef ROOMCARD_H
#define ROOMCARD_H

#include "BoardEnums.h"
#include "Card.h"
#include <QString>

/**
 * @brief The RoomCard class represents a Clue Room Card
 */
class RoomCard : public Card
{
public:
    /**
     * @brief RoomCard Explicit Constructor
     * @param identifier CardEnum
     * @param name QString
     */
    explicit RoomCard(CardEnum identifier, QString name);

    /**
      * @brief ~RoomCard Destructor
      */
    ~RoomCard();
};

#endif // ROOMCARD_H
