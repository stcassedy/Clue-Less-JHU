/**
  * @file Card.cpp
  */
#include "Card.h"

// -----------------------------------------------------------------------------
// Constructor:
Card::Card(CardTypeEnum type, CardEnum identifier, QString name)
{
    m_type = type;
    m_identifier = identifier;
    m_name = name;
}

// -----------------------------------------------------------------------------
// Destructor:
Card::~Card()
{

}

// -----------------------------------------------------------------------------
// Public Functions:
CardTypeEnum Card::getCardType()
{
    return m_type;
}

CardEnum Card::getCardIdentifier()
{
    return m_identifier;
}

QString Card::getCardName()
{
    return m_name;
}
