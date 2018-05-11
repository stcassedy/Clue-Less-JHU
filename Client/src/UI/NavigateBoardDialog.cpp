/**
  * @file NavigateBoardDialog.cpp
  */
#include "NavigateBoardDialog.h"
#include "ui_NavigateBoardDialog.h"
#include "Board.h"
#include "ClientManager.h"
#include "Player.h"
#include "BoardElement.h"

// -----------------------------------------------------------------------------
// Constructor:
NavigateBoardDialog::NavigateBoardDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::NavigateBoardDialog)
{
    //sets up the UI
    m_ui->setupUi(this);
    setModal(true);
    setWindowTitle("Navigate Board");
}

// -----------------------------------------------------------------------------
// Destructor:
NavigateBoardDialog::~NavigateBoardDialog()
{
    delete m_ui;
}

// -----------------------------------------------------------------------------
// Public Slots:
void NavigateBoardDialog::show()
{
    //enables/disables buttons
    m_ui->btnStudy->setEnabled(studyIsValid());
    m_ui->btnHall->setEnabled(hallIsValid());
    m_ui->btnLounge->setEnabled(loungeIsValid());
    m_ui->btnLibrary->setEnabled(libraryIsValid());
    m_ui->btnBilliardRoom->setEnabled(billiardRoomIsValid());
    m_ui->btnDiningRoom->setEnabled(diningRoomIsValid());
    m_ui->btnConservatory->setEnabled(conservatoryIsValid());
    m_ui->btnBallroom->setEnabled(ballroomIsValid());
    m_ui->btnKitchen->setEnabled(kitchenIsValid());
    m_ui->btnHallway1->setEnabled(hallway1IsValid());
    m_ui->btnHallway2->setEnabled(hallway2IsValid());
    m_ui->btnHallway3->setEnabled(hallway3IsValid());
    m_ui->btnHallway4->setEnabled(hallway4IsValid());
    m_ui->btnHallway5->setEnabled(hallway5IsValid());
    m_ui->btnHallway6->setEnabled(hallway6IsValid());
    m_ui->btnHallway7->setEnabled(hallway7IsValid());
    m_ui->btnHallway8->setEnabled(hallway8IsValid());
    m_ui->btnHallway9->setEnabled(hallway9IsValid());
    m_ui->btnHallway10->setEnabled(hallway10IsValid());
    m_ui->btnHallway11->setEnabled(hallway11IsValid());
    m_ui->btnHallway12->setEnabled(hallway12IsValid());

    //shows the dialog
    QWidget::show();
}


// -----------------------------------------------------------------------------
// Private Slots:
void NavigateBoardDialog::on_btnStudy_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(STUDY);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHall_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALL);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnLounge_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(LOUNGE);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnLibrary_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(LIBRARY);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnBilliardRoom_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(BILLIARD_ROOM);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnDiningRoom_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(DINING_ROOM);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnConservatory_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(CONSERVATORY);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnBallroom_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(BALLROOM);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnKitchen_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(KITCHEN);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway1_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_1);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway2_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_2);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway3_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_3);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway4_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_4);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway5_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_5);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway6_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_6);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway7_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_7);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway8_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_8);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway9_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_9);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway10_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_10);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway11_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_11);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway12_clicked()
{
    //tells the client manager to move the player to a new location
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_12);
    ClientManager::getInstance()->movePlayer(elem);

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnCancel_clicked()
{
    //closes the dialog
    close();
}

// -----------------------------------------------------------------------------
// Private Functions:
bool NavigateBoardDialog::studyIsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(STUDY);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallIsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALL);
    return isValidMove(elem);
}

bool NavigateBoardDialog::loungeIsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(LOUNGE);
    return isValidMove(elem);
}

bool NavigateBoardDialog::libraryIsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(LIBRARY);
    return isValidMove(elem);
}

bool NavigateBoardDialog::billiardRoomIsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(BILLIARD_ROOM);
    return isValidMove(elem);
}

bool NavigateBoardDialog::diningRoomIsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(DINING_ROOM);
    return isValidMove(elem);
}

bool NavigateBoardDialog::conservatoryIsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(CONSERVATORY);
    return isValidMove(elem);
}

bool NavigateBoardDialog::ballroomIsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(BALLROOM);
    return isValidMove(elem);
}

bool NavigateBoardDialog::kitchenIsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(KITCHEN);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway1IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_1);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway2IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_2);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway3IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_3);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway4IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_4);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway5IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_5);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway6IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_6);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway7IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_7);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway8IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_8);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway9IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_9);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway10IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_10);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway11IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_11);
    return isValidMove(elem);
}

bool NavigateBoardDialog::hallway12IsValid()
{
    //Determines if the location is a valid move
    BoardElement* elem = Board::getInstance()->getBoardElement(HALLWAY_12);
    return isValidMove(elem);
}

bool NavigateBoardDialog::isValidMove(BoardElement* elem)
{
    //gets the connected location list
    Player* player = ClientManager::getInstance()->getCurrentPlayer();
    BoardElement* currentLocation = player->getCurrentLocation();
    QList<BoardElement*> elemList = currentLocation->getConnectedElements();

    //checks if the board element is connected and open for a new player
    return (elemList.contains(elem) && elem->openForNewPlayer());
}
