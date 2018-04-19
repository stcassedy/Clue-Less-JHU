/**
  * @file Card.h
  */
#ifndef CARD_H
#define CARD_H

#include "Board.h"
#include <QString>

/**
 * @brief The Card class represents a generic Clue Card
 */
class Card
{
public:
    /**
     * @brief Card Constructor
     * @param type CardTypeEnum
     * @param identifier CardEnum
     * @param name QString
     */
    Card(CardTypeEnum type, CardEnum identifier, QString name);

    /**
      * @brief ~Card Destructor
      */
    ~Card();

    /**
     * @brief getCardType returns the card type
     * @return CardTypeEnum
     */
    CardTypeEnum getCardType();

    /**
     * @brief getCardIdentifier returns the CardEnum
     * @return CardEnum
     */
    CardEnum getCardIdentifier();

    /**
     * @brief getCardName returns the card name
     * @return QString
     */
    QString getCardName();

private:
    //Member Variables
    CardTypeEnum m_type;
    CardEnum m_identifier;
    QString m_name;
};

#endif // CARD_H
