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
#include "Board.h"

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
    //gets lists of the player cards
    Player* player = ClientManager::getInstance()->getCurrentPlayer();
    QList<WeaponCard*> weaponCardList = player->getWeaponCards();
    QList<RoomCard*> roomCardList = player->getRoomCards();
    QList<PlayerCard*> playerCardList = player->getPlayerCards();

    //clears the combo box before adding to it
    m_ui->cbRefutation->clear();

    //tracks if the player can refute the cards
    bool refutable = false;

    //checks if the player has the weapon card
    if (weaponCardList.contains(m_weaponCard))
    {
        //adds the weapon card to the combo box
        m_ui->cbRefutation->addItem(m_weaponCard->getCardName());

        //the cards are refutable
        refutable = true;
    }

    //checks if the player has the room card
    if (roomCardList.contains(m_roomCard))
    {
        //adds the room card to the combo box
        m_ui->cbRefutation->addItem(m_roomCard->getCardName());

        //the cards are refutable
        refutable = true;
    }

    //checks if the player has the player card
    if (playerCardList.contains(m_playerCard))
    {
        //adds the player card to the combo box
        m_ui->cbRefutation->addItem(m_playerCard->getCardName());

        //the cards are refutable
        refutable = true;
    }

    //enables/disables the refute button
    m_ui->btnRefute->setEnabled(refutable);

    //shows the dialog
    QWidget::show();
}

// -----------------------------------------------------------------------------
// Private Slots:
void RefutationDialog::on_btnRefute_clicked()
{
    //gets card for refutation based on the combo box selection
    QString name = m_ui->cbRefutation->currentText();
    CardEnum cardEnum = getCardEnumFromName(name);
    Card* card = Board::getInstance()->getCard(cardEnum);

    //notifies client manager of suggestion refutation
    ClientManager::getInstance()->refuteSuggestion(card);

    //closes the dialog
    close();
}

void RefutationDialog::on_btnCancel_clicked()
{
    //closes the dialog
    close();
}


// -----------------------------------------------------------------------------
// Private:
CardEnum RefutationDialog::getCardEnumFromName(QString name)
{
    if (name == "Candlestick")
    {
        return CANDLESTICK_CARD;
    }
    else if (name == "Knife")
    {
        return KNIFE_CARD;
    }
    else if (name == "Lead Pipe")
    {
        return LEAD_PIPE_CARD;
    }
    else if (name == "Revolver")
    {
        return REVOLVER_CARD;
    }
    else if (name == "Rope")
    {
        return ROPE_CARD;
    }
    else if (name == "Wrench")
    {
        return WRENCH_CARD;
    }
    else if (name == "Miss Scarlet")
    {
        return SCARLET_CARD;
    }
    else if (name == "Colonel Mustard")
    {
        return MUSTARD_CARD;
    }
    else if (name == "Mrs. White")
    {
        return WHITE_CARD;
    }
    else if (name == "Mr. Green")
    {
        return GREEN_CARD;
    }
    else if (name == "Mrs. Peacock")
    {
        return PEACOCK_CARD;
    }
    else if (name == "Professor Plum")
    {
        return PLUM_CARD;
    }
    else if (name == "Kitchen")
    {
        return KITCHEN_CARD;
    }
    else if (name == "Ballroom")
    {
        return BALLROOM_CARD;
    }
    else if (name == "Conservatory")
    {
        return CONSERVATORY_CARD;
    }
    else if (name == "Dining Room")
    {
        return DINING_ROOM_CARD;
    }
    else if (name == "Billiard Room")
    {
        return BILLIARD_ROOM_CARD;
    }
    else if (name == "Library")
    {
        return LIBRARY_CARD;
    }
    else if (name == "Lounge")
    {
        return LOUNGE_CARD;
    }
    else if (name == "Hall")
    {
        return HALL_CARD;
    }
    else
    {
        return STUDY_CARD;
    }
}
