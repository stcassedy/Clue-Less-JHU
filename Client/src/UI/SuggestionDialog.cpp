/**
 * @file SuggestionDialog.cpp
 */
#include "SuggestionDialog.h"
#include "ui_SuggestionDialog.h"
#include "Envelope.h"
#include "WeaponCard.h"
#include "RoomCard.h"
#include "PlayerCard.h"
#include "Board.h"
#include "ClientManager.h"
#include "Player.h"
#include "BoardElement.h"

// -----------------------------------------------------------------------------
// Constructor:
SuggestionDialog::SuggestionDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::SuggestionDialog)
{
    //sets up the UI
    m_ui->setupUi(this);
    setModal(true);
    setWindowTitle("Suggestion");
}

// -----------------------------------------------------------------------------
// Destructor:
SuggestionDialog::~SuggestionDialog()
{
    delete m_ui;
}

// -----------------------------------------------------------------------------
// Private Slots:
void SuggestionDialog::on_btnSuggest_clicked()
{
    //generic card pointer
    Card* card;

    //gets a pointer to the weapon card
    card = Board::getInstance()->getCard(getWeaponCardEnum());
    WeaponCard* weapon = dynamic_cast<WeaponCard*>(card);

    //gets a pointer to the room card
    card = Board::getInstance()->getCard(getRoomCardEnum());
    RoomCard* room = dynamic_cast<RoomCard*>(card);

    //gets a pointer to the room card
    card = Board::getInstance()->getCard(getPlayerCardEnum());
    PlayerCard* player = dynamic_cast<PlayerCard*>(card);

    //makes a suggestion to the client manager
    ClientManager::getInstance()->makeSuggestion(room, player, weapon);

    //closes the dialog
    close();
}

void SuggestionDialog::on_btnCancel_clicked()
{
    //closes the dialog
    close();
}

// -----------------------------------------------------------------------------
// Private Functions:
CardEnum SuggestionDialog::getWeaponCardEnum()
{
    if (m_ui->cbWeapon->currentIndex() == 0)
    {
        return CANDLESTICK_CARD;
    }
    else if (m_ui->cbWeapon->currentIndex() == 1)
    {
        return KNIFE_CARD;
    }
    else if (m_ui->cbWeapon->currentIndex() == 2)
    {
        return LEAD_PIPE_CARD;
    }
    else if (m_ui->cbWeapon->currentIndex() == 3)
    {
        return REVOLVER_CARD;
    }
    else if (m_ui->cbWeapon->currentIndex() == 4)
    {
        return ROPE_CARD;
    }
    else
    {
        return WRENCH_CARD;
    }
}

CardEnum SuggestionDialog::getRoomCardEnum()
{
    //returns the room card for the current player's location
    Player* player = ClientManager::getInstance()->getCurrentPlayer();
    BoardElement* elem = player->getCurrentLocation();

    //determines the card based on the room
    if(elem->getBoardElementEnum() == STUDY)
    {
        return STUDY_CARD;
    }
    else if (elem->getBoardElementEnum() == HALL)
    {
        return HALL_CARD;
    }
    else if (elem->getBoardElementEnum() == LOUNGE)
    {
        return LOUNGE_CARD;
    }
    else if (elem->getBoardElementEnum() == LIBRARY)
    {
        return LIBRARY_CARD;
    }
    else if (elem->getBoardElementEnum() == BILLIARD_ROOM)
    {
        return BILLIARD_ROOM_CARD;
    }
    else if (elem->getBoardElementEnum() == DINING_ROOM)
    {
        return DINING_ROOM_CARD;
    }
    else if (elem->getBoardElementEnum() == CONSERVATORY)
    {
        return CONSERVATORY_CARD;
    }
    else if (elem->getBoardElementEnum() == BALLROOM)
    {
        return BALLROOM_CARD;
    }
    else
    {
        return KITCHEN_CARD;
    }
}

CardEnum SuggestionDialog::getPlayerCardEnum()
{
    if (m_ui->cbSuspect->currentIndex() == 0)
    {
        return SCARLET_CARD;
    }
    else if (m_ui->cbSuspect->currentIndex() == 1)
    {
        return MUSTARD_CARD;
    }
    else if (m_ui->cbSuspect->currentIndex() == 2)
    {
        return WHITE_CARD;
    }
    else if (m_ui->cbSuspect->currentIndex() == 3)
    {
        return GREEN_CARD;
    }
    else if (m_ui->cbSuspect->currentIndex() == 4)
    {
        return PEACOCK_CARD;
    }
    else
    {
        return PLUM_CARD;
    }
}

