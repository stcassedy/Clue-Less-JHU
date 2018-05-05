/**
  * @file Hallway.h
  */
#ifndef HALLWAY_H
#define HALLWAY_H

#include "BoardEnums.h"
#include "BoardElement.h"
#include <QList>

/**
* @brief The Hallway class represents a Hallway on the Clue board
*/
class Hallway : public BoardElement
{
public:
    /**
	* @brief Hallway explicit constructor
	* @param loc LocationEnum
	*/
    explicit Hallway(LocationEnum loc);

    /**
      * @brief ~Hallway Destructor
      */
    ~Hallway();

	/**
     * @brief openForNewPlayer returns if a new player can occupy the space
     * or not
     * @return CardEnum
     */
    bool openForNewPlayer();
};

#endif // HALLWAY_H
