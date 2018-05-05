#include "Player.h"
#include "Board.h"


// -----------------------------------------------------------------------------
// Constructor:
Player::Player(PlayerEnum playerNumIn, LocationEnum loc)
{
    playerNum = playerNumIn;
    currentLocation = loc;
    //by deafult connected will be false
    connected = false;
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
    //Add card pointer to Hand object
    hand.addCard(card);
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
