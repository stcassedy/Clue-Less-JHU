#ifndef BOARDELEMENT_H
#define BOARDELEMENT_H

#include "BoardEnums.h"
#include "QList"

/**
 * @brief The BoardElements class represents a board element, either a Room or Hallway
 */
class BoardElement
{
private:
    LocationTypeEnum type;
    LocationEnum location;
    QList<LocationEnum> connected;
    QList<PlayerEnum> players;

public:
    /**
     * @brief BoardElement Explicit Constructor
     * @param type LocationTypeEnum
     * @param loc LocationEnum
     */
    explicit BoardElement(LocationTypeEnum type, LocationEnum loc);

    /**
     * @brief BoardElement Destructor
     */
    ~BoardElement();

    /**
     * @brief getBoardElementType returns LocationTypeEnum
     */
    LocationTypeEnum getBoardElementType();

    /**
     * @brief getBoardElementEnum returns LocationEnum
     */
    LocationEnum getBoardElementEnum();

    /**
     * @brief getConnectedElements returns list of connected elements
     */
    QList<LocationEnum> getConnectedElements();

    /**
      * @brief addPlayer adds a player to player list
      */
    void addPlayer(PlayerEnum);

    /**
      * @brief removePlayer removes a player from player list
      */
    void removePlayer(PlayerEnum);

    /**
      * @brief isSpaceAvailable returns true if the player can move there
      */
    bool isSpaceAvailable(LocationEnum);

    /**
     * @brief isBoardElementConnected, returns true if LocationEnum supplied a valid move
     * @param loc LocationEnum
     */
    bool isBoardElementConnected(LocationEnum loc);

};



#endif // BOARDELEMENT_H
