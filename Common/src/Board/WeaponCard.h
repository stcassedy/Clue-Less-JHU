/**
  * @file WeaponCard.h
  */
#ifndef WEAPONCARD_H
#define WEAPONCARD_H

#include "Board.h"
#include "Card.h"
#include <QString>

/**
 * @brief The WeaponCard class represents a Clue Weapon Card
 */
class WeaponCard : public Card
{
public:
    /**
     * @brief WeaponCard Construtor
     * @param identifier CardEnum
     * @param name QString
     */
    WeaponCard(CardEnum identifier, QString name);

    /**
      * @brief ~WeaponCard Destructor
      */
    ~WeaponCard();
};

#endif // WEAPONCARD_H
