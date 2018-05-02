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
    int type, location;
    QList<LocationEnum> locId;

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
     * @brief isBoardElementConnected, returns true if LocationEnum supplied is connected to BoardElement
     * @param loc LocationEnum
     */
    bool isBoardElementConnected(LocationEnum loc);
};

#endif // BOARDELEMENT_H
