/**
  * @file PlayerCard.h
  */
#ifndef PLAYERCARD_H
#define PLAYERCARD_H

#include "BoardEnums.h"
#include "Card.h"
#include <QString>

/**
 * @brief The PlayerCard class represents a Clue Suspect Card
 */
class PlayerCard : public Card
{
public:
    /**
     * @brief PlayerCard Explicit Constructor
     * @param identifier CardEnum
     * @param name QString
     */
    explicit PlayerCard(CardEnum identifier, QString name);

    /**
      * @brief ~PlayerCard Destructor
      */
    ~PlayerCard();
};

#endif // PLAYERCARD_H
