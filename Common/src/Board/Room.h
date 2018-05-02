/**
  * @file Room.h
  */
#ifndef ROOM_H
#define ROOM_H

#include "BoardEnums.h"
#include "BoardElement.h"
#include <QList>

/**
* @brief The Room class represents a Room on the Clue board
*/
class Room : public BoardElement
{
public:
	/**
	* @brief Room explicit constructor
	* @param loc LocationEnum
	* @param connectedLocList QList<LocationEnum>
	*/
    explicit Room(LocationEnum loc, QList<LocationEnum> connectedLocList);

    /**
      * @brief ~Room Destructor
      */
    ~Room();

	/**
     * @brief openForNewPlayer returns if a new player can occupy the space or not
     * @return boolean
     */
    bool openForNewPlayer();

private:
	//Member Variables
	QList<LocationEnum> connectedHallways_;
	QList<LocationEnum> connectedRooms_;
};

#endif // ROOM_H