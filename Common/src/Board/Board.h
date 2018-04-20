#ifndef BOARD_H
#define BOARD_H

#include <QMap>
#include "Envelope.h"
#include "BoardEnums.h"

//Forward Declarations
class Card;

/**
 * @brief The Board class is a singleton class that primarily provides lookup
 * utility functions. The board state is determined by attributes in this class.
 */
class Board
{
public:
    /**
     * @brief getInstance Returns a pointer to the board instance
     * @return Board*
     */
    static Board* getInstance();

    /**
     * @brief getCard Looks up and returns a pointer to a card object based on
     * a CardEnum
     * @param card CardEnum
     * @return Card*
     */
    Card* getCard(CardEnum card);

    /**
     * @brief getHiddenEnvelope returns a pointer to the hidden evelope
     * @return Envelope*
     */
    Envelope* getHiddenEnvelope();

private:
    /**
     * @brief Board Constructor
     */
    Board();

    /**
      * @brief ~Board Destructor
      */
    ~Board();

    /**
     * @brief initializeCardLookup Initializes the Card Lookup map and all of
     * the cards
     */
    void initializeCardLookup();

    //Member Variables
    static Board m_instance;
    QMap<int, Card*> m_cardLookup;
    Envelope m_envelope;

};

#endif // BOARD_H
