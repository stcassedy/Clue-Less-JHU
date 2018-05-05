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
    LocationTypeEnum m_type;
    LocationEnum m_location;
    QList<LocationEnum> m_connected;
    QList<PlayerEnum> m_players;

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
    virtual ~BoardElement();

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
    bool isSpaceAvailable();

    /**
     * @brief isBoardElementConnected, returns true if LocationEnum supplied a valid move
     * @param loc LocationEnum
     */
    bool isBoardElementConnected(LocationEnum loc);


    /**
      * @brief playersInElement returs the players in the element
      */
    QList<PlayerEnum> playersInElement();

    /**
     * @brief openForNewPlayer (Abstract) Determines if a player can move into
     * the board element
     * @return bool true if the location can accept a player, false otherwise
     */
    virtual bool openForNewPlayer() = 0;

};



#endif // BOARDELEMENT_H
