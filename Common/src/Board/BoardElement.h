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
    QList<LocationEnum> locId;
    static bool occupied;

public:
    /**
     * @brief BoardElement Explicit Constructor
     * @param type LocationTypeEnum
     * @param loc LocationEnum
     * @param locId QList<LocationEnum>
     */
    explicit BoardElement(LocationTypeEnum type, LocationEnum loc, QList<LocationEnum> locId);

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

    /*
     * I dont think this is necessary, we only need isBoardElementConnected
    QList<LocationEnum> getConnectedElements();
    */

    /*
     * I dont think we need this since its basically the same as getBoardElementType
    bool isRoom();
    */


    /**
     * @brief openForNewPlayer, true if someone is in element
     */
    bool openForNewPlayer();

    /**
     * @brief setOccupied, sets if BoardElement is occupied
     */
    void setOccupied(bool set);

    /**
     * @brief isBoardElementConnected, returns true if LocationEnum supplied a valid move
     * @param loc LocationEnum
     */
    bool isBoardElementConnected(LocationEnum loc);

};



#endif // BOARDELEMENT_H
