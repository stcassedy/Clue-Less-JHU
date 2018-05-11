#include "Player.h"
#include "Board.h"
#include "Card.h"


// -----------------------------------------------------------------------------
// Constructor:
Player::Player(PlayerEnum playerNumIn, LocationEnum loc) :
    playerNum(playerNumIn),
    currentLocation(loc),
    connected(false),
    m_stillInGame(true)
{
}

// -----------------------------------------------------------------------------
// Destructor:
Player::~Player()
{

}

// -----------------------------------------------------------------------------
// Public Functions:
PlayerEnum Player::getPlayerNum()
{
    return playerNum;
}


BoardElement* Player::getCurrentLocation()
{
    //Look up BoardElement from Board instance
    BoardElement* currentElement =
            Board::getInstance()->getBoardElement(currentLocation);
    return currentElement;
}


QList<Card*> Player::getHandCards()
{
    return hand.getCardList();
}


void Player::giveCard(Card* card)
{
    //tosses invalid cards
    if (card->getCardIdentifier() != INVALID_CARD)
    {
        //Add card pointer to Hand object
        hand.addCard(card);
    }
}


bool Player::handContains(Card* card)
{
    //Check if hand contains Card, using Hand class function
    return hand.containsCard(card);
}


QList<WeaponCard*> Player::getWeaponCards()
{
    return hand.getWeaponCardList();
}


QList<PlayerCard*> Player::getPlayerCards()
{
    return hand.getPlayerCardList();
}


QList<RoomCard*> Player::getRoomCards()
{
    return hand.getRoomCardList();
}


void Player::move(BoardElement* loc)
{
    //Update player location
    currentLocation = loc->getBoardElementEnum();
}


bool Player::isConnected()
{
    return connected;
}


void Player::setConnected(bool connectedIn)
{
    connected = connectedIn;
}

void Player::playerLost()
{
    m_stillInGame = false;
}

bool Player::playerStillInGame()
{
    return m_stillInGame;
}
