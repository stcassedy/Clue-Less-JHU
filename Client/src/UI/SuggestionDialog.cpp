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


    //builds envelope to pass to the client manager
    Envelope env;
    env.setWeaponCard(weapon);
    env.setRoomCard(room);
    env.setPlayerCard(player);

    //TODO: pass envelope to the client manager

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
    //TODO: get current location from player

    return STUDY_CARD;
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

