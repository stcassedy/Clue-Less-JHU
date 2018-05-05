/**
  * @file RefutationDialog.cpp
  */
#include "RefutationDialog.h"
#include "ui_RefutationDialog.h"
#include "WeaponCard.h"
#include "RoomCard.h"
#include "PlayerCard.h"
#include "Player.h"
#include "ClientManager.h"

// -----------------------------------------------------------------------------
// Static Member Variables:
WeaponCard* RefutationDialog::m_weaponCard = NULL;
RoomCard* RefutationDialog::m_roomCard = NULL;
PlayerCard* RefutationDialog::m_playerCard = NULL;

// -----------------------------------------------------------------------------
// Constructor:
RefutationDialog::RefutationDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::RefutationDialog)
{
    //sets up the UI
    m_ui->setupUi(this);
    setModal(true);
    setWindowTitle("Refutation");
}

// -----------------------------------------------------------------------------
// Destructor:
RefutationDialog::~RefutationDialog()
{
    delete m_ui;
}

// -----------------------------------------------------------------------------
// Public Functions:
void RefutationDialog::setSuggestionCards(WeaponCard *wCard, RoomCard *rCard,
                                          PlayerCard *pCard)
{
    //sets pointers to the cards that need refuted
    m_weaponCard = wCard;
    m_roomCard = rCard;
    m_playerCard = pCard;
}

// -----------------------------------------------------------------------------
// Public Slots:
void RefutationDialog::show()
{
    //TODO: Add valid refutation cards to the combo box
    //TODO: if no valid refutation cards enable Pass button, otherwise disable
    //TODO: if valid refucation cards enable Refute button, otherwise disable


    //shows the dialog
    QWidget::show();
}

// -----------------------------------------------------------------------------
// Private Slots:
void RefutationDialog::on_btnRefute_clicked()
{
    //TODO: Notify the Client Manager of the Refutation Card

    //closes the dialog
    close();
}

void RefutationDialog::on_btnPass_clicked()
{
    //TODO: Notify the Client Manager of the pass

    //closes the dialog
    close();
}

void RefutationDialog::on_btnCancel_clicked()
{
    //closes the dialog
    close();
}
