#ifndef BOARD_H
#define BOARD_H

#include <QMap>

//Forward Declarations
class Card;

/**
 * @brief The CardTypeEnum enum
 */
enum CardTypeEnum
{
    WEAPON_CARD = 0,
    ROOM_CARD,
    PLAYER_CARD
};

/**
 * @brief The CardEnum enum
 */
enum CardEnum
{
    CANDLESTICK_CARD = 0,
    KNIFE_CARD,
    LEAD_PIPE_CARD,
    REVOLVER_CARD,
    ROPE_CARD,
    WRENCH_CARD,
    SCARLET_CARD,
    MUSTARD_CARD,
    WHITE_CARD,
    GREEN_CARD,
    PEACOCK_CARD,
    PLUM_CARD,
    KITCHEN_CARD,
    BALLROOM_CARD,
    CONSERVATORY_CARD,
    DINING_ROOM_CARD,
    BILLIARD_ROOM_CARD,
    LIBRARY_CARD,
    LOUNGE_CARD,
    HALL_CARD,
    STUDY_CARD
};

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
    Board* getInstance();

    /**
     * @brief getCard Looks up and returns a pointer to a card object based on
     * a CardEnum
     * @param card CardEnum
     * @return Card*
     */
    Card* getCard(CardEnum card);

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
    Board* m_instance;
    QMap<int, Card*> m_cardLookup;

};

#endif // BOARD_H
