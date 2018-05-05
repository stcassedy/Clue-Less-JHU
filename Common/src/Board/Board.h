/**
  * @file Board.h
  */
#ifndef BOARD_H
#define BOARD_H

#include <QMap>
#include "Envelope.h"
#include "BoardEnums.h"

//Forward Declarations
class Card;
class Player;
class BoardElement;

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
     * @brief getPlayer Looks up and returns a pointer to a player
     * object based on a player enum
     * @param player PlayerEnum
     * @return Player*
     */
    Player* getPlayer(PlayerEnum player);

    /**
     * @brief getBoardElement Looks up and returns a pointer to a board element
     * object based on a location enum
     * @param loc LocationEnum
     * @return BoardElement*
     */
    BoardElement* getBoardElement(LocationEnum loc);

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
     * @brief initializeCardLookup Initializes the card lookup map and all of
     * the card objects
     */
    void initializeCardLookup();

    /**
     * @brief initializePlayerLookup Initializes the player lookup map and all
     * of the player objects
     */
    void initializePlayerLookup();

    /**
     * @brief initializeBoardElementLookup Initializes the board element lookup
     * map and all of the board element objects
     */
    void initializeBoardElementLookup();

    //Member Variables
    static Board m_instance;
    QMap<int, Card*> m_cardLookup;
    QMap<int, Player*> m_playerLookup;
    QMap<int, BoardElement*> m_boardElementLookup;
    Envelope m_envelope;

};

#endif // BOARD_H
