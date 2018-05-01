#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include "BoardEnums.h"
#include "BoardElement.h"
#include <QList>

/**
 * @brief The Player class holds the player board information
 */
class Player
{
public:
    /**
     * @brief explicit Player constructor
     * @param playerNum PlayerEnum
     * @param loc LocationEnum
     */
    explicit Player(PlayerEnum playerNum, LocationEnum loc);

    /**
      * @brief Player desconstructor
      */
    virtual ~Player();

    /**
     * @brief getPlayerNum returns the Player enum value
     * @return PlayerEnum
     */
    PlayerEnum getPlayerNum();

    /**
     * @brief getCurrentLocation returns the users location
     * @return BoardElement*
     */
    BoardElement* getCurrentLocation();

    /**
     * @brief getHandCards returns the Cards in the players Hand
     * @return QList<Card*>
     */
    QList<Card*> getHandCards();

    /**
     * @brief adds Card to the players Hand
     * @param Card* to add
     */
    void giveCard(Card* card);

    /**
     * @brief handContains returns if the card is in the players hand
     * @param card Card* to check for
     * @return bool
     */
    bool handContains(Card* card);

    /**
     * @brief getWeaponCards returns the WeaponCards in the players hand
     * @return QList<WeaponCard*>
     */
    QList<WeaponCard*> getWeaponCards();

    /**
     * @brief getPlayerCards returns the PlayerCards in the players hand
     * @return QList<PlayerCard*>
     */
    QList<PlayerCard*> getPlayerCards();

    /**
     * @brief getRoomCards returns the RoomCards in the players hand
     * @return QList<RoomCard*>
     */
    QList<RoomCard*> getRoomCards();

    /**
     * @brief move sets the current location to the given BoardElement
     * @param loc BoardElement* to move to
     */
    void move(BoardElement* loc);

    /**
     * @brief isConnected returns if the player is currently connected to the game server
     * @return bool
     */
    bool isConnected();

    /**
     * @brief setConnected changes the connection bool to the parameter
     * @param connected bool
     */
    void setConnected(bool connected);
private:
    //Member variables
    PlayerEnum playerNum;
    LocationEnum currentLocation;
    Hand hand;
    bool connected;
};

#endif // PLAYER_H
