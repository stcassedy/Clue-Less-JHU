/**
  * @file Envelope.h
  */
#ifndef ENVELOPE_H
#define ENVELOPE_H

#include "BoardEnums.h"

//Forward Declaration
class WeaponCard;
class RoomCard;
class PlayerCard;

/**
 * @brief The Envelope class represents the envelope containing the hidden cards
 */
class Envelope
{
public:
    /**
     * @brief Envelope Explicit Constructor
     */
    explicit Envelope();

    /**
      * @brief ~Envelope Destructor
      */
    ~Envelope();

    /**
     * @brief setWeaponCard sets the hidden weapon card
     * @param card WeaponCard*
     */
    void setWeaponCard(WeaponCard* card);

    /**
     * @brief setRoomCard sets the hidden room card
     * @param card RoomCard*
     */
    void setRoomCard(RoomCard* card);

    /**
     * @brief setPlayerCard sets the hidden player card
     * @param card PlayerCard*
     */
    void setPlayerCard(PlayerCard* card);

    /**
     * @brief isAccusationCorrect determines if an accusation is correct
     * @param env Envelope*
     * @return bool true if accusation is correct, false otherwise
     */
    bool isAccusationCorrect(Envelope* env);

    int getWeaponCard();

    int getRoomCard();

    int getPlayerCard();

protected:
    //Member Variables
    int m_weapon;
    int m_room;
    int m_player;
};

#endif // ENVELOPE_H
