/**
 * @file ClientWindow.cpp
 */
#include "ClientWindow.h"
#include "ui_ClientWindow.h"
#include "Board.h"
#include "Player.h"

// -----------------------------------------------------------------------------
// Constants:
static const int START_PAGE = 0;
static const int CHARACTER_SELECTION_PAGE = 1;
static const int GAME_BOARD_PAGE = 2;
static const int CONNECTION_ERROR_PAGE = 3;
static const QString READY_TEXT = "Ready!";
static const QString NOT_READY_TEXT = "Not Ready Yet";

// -----------------------------------------------------------------------------
// Constructor:
ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::ClientWindow),
    m_navigateBoardDlg(parent),
    m_suggestionDlg(parent),
    m_accusationDlg(parent),
    m_refutationDlg(parent),
    m_notebookDlg(parent)
{
    //sets up the UI
    m_ui->setupUi(this);
    setWindowTitle("Clue-Less");

    //defaults to start page
    m_ui->stackedWidget->setCurrentIndex(START_PAGE);

    //updates board elements with pointers to UI elements
    updateBoardElementUI();

    //hides all of the player location labels
    hideAllPlayerLabels();

    //updates the UI
    updateUI();
}

// -----------------------------------------------------------------------------
// Destructor:
ClientWindow::~ClientWindow()
{
    delete m_ui;
}

// -----------------------------------------------------------------------------
// Public:
void ClientWindow::updateUI()
{
    //hides all of the player location labels
    hideAllPlayerLabels();

    //updates the player locations
    updateScarletLocation();
    updateMustardLocation();
    updateWhiteLocation();
    updateGreenLocation();
    updatePeacockLocation();
    updatePlumLocation();
}

// -----------------------------------------------------------------------------
// Private Slots:
void ClientWindow::on_btnJoinGame_clicked()
{
    //if there is a connection to the server
//    if ()
//    {
        //show character selection page
    m_ui->stackedWidget->setCurrentIndex(CHARACTER_SELECTION_PAGE);
//    }
//    else
//    {
//        //show connection error page
//        ui->stackedWidget->setCurrentIndex(CONNECTION_ERROR_PAGE);
//    }

    //Prepares the start game widgets
//    ui->btnStartGame->setDisabled(true);

    //TODO: determine player number from server
    //enables the combo box and ready button for the player
}

void ClientWindow::on_btnStartGame_clicked()
{
    //show game board page
    m_ui->stackedWidget->setCurrentIndex(GAME_BOARD_PAGE);

    //TODO: load current board state

}

void ClientWindow::on_btnAckNoServer_clicked()
{
    //show the start page
    m_ui->stackedWidget->setCurrentIndex(START_PAGE);
}

void ClientWindow::on_btnNavigateBoard_clicked()
{
    //shows the navigate board dialog
    m_navigateBoardDlg.show();
}

void ClientWindow::on_btnMakeSuggestion_clicked()
{
    //shows the suggestion dialog
    m_suggestionDlg.show();
}

void ClientWindow::on_btnRefute_clicked()
{
    //shows the refutation dialog
    m_refutationDlg.show();
}

void ClientWindow::on_btnMakeAccusation_clicked()
{
    //shows the accusation dialog
    m_accusationDlg.show();
}

void ClientWindow::on_btnViewNotebook_clicked()
{
    //shows the notebook dialog
    m_notebookDlg.show();
}

// -----------------------------------------------------------------------------
// Private:
void ClientWindow::hideAllPlayerLabels()
{
    //gets a list of the board elements
    QList<BoardElement*> elemList = Board::getInstance()->getAllBoardElements();

    //iterates through the board elements
    for (int i = 0; i < elemList.size(); ++i)
    {
        //hides the player UI labels
        elemList.at(i)->hideAllLabels();
    }
}

void ClientWindow::updateScarletLocation()
{
    //shows the scarlet player in the current player location
    Player* scarlet = Board::getInstance()->getPlayer(MISS_SCARLET);
    BoardElement* elem = scarlet->getCurrentLocation();
    elem->getScarletLabel()->show();
}


void ClientWindow::updateMustardLocation()
{
    //shows the mustard player in the current player location
    Player* mustard = Board::getInstance()->getPlayer(COL_MUSTARD);
    BoardElement* elem = mustard->getCurrentLocation();
    elem->getMustardLabel()->show();
}

void ClientWindow::updateWhiteLocation()
{
    //shows the white player in the current player location
    Player* white = Board::getInstance()->getPlayer(MRS_WHITE);
    BoardElement* elem = white->getCurrentLocation();
    elem->getWhiteLabel()->show();
}

void ClientWindow::updateGreenLocation()
{
    //shows the green player in the current player location
    Player* green = Board::getInstance()->getPlayer(MR_GREEN);
    BoardElement* elem = green->getCurrentLocation();
    elem->getGreenLabel()->show();
}

void ClientWindow::updatePeacockLocation()
{
    //shows the peacock player in the current player location
    Player* peacock = Board::getInstance()->getPlayer(MRS_PEACOCK);
    BoardElement* elem = peacock->getCurrentLocation();
    elem->getPeacockLabel()->show();
}

void ClientWindow::updatePlumLocation()
{
    //shows the plum player in the current player location
    Player* plum = Board::getInstance()->getPlayer(PROF_PLUM);
    BoardElement* elem = plum->getCurrentLocation();
    elem->getPlumLabel()->show();
}

void ClientWindow::updateBoardElementUI()
{
    //pointer to the board elements
    BoardElement* elem;

    //gets Study elements and sets UI
    elem = Board::getInstance()->getBoardElement(STUDY);
    elem->setScarletLabel(m_ui->lbStudyScarlet);
    elem->setMustardLabel(m_ui->lbStudyMustard);
    elem->setWhiteLabel(m_ui->lbStudyWhite);
    elem->setGreenLabel(m_ui->lbStudyGreen);
    elem->setPeacockLabel(m_ui->lbStudyPeacock);
    elem->setPlumLabel(m_ui->lbStudyPlum);

    //gets Lounge elements and sets UI
    elem = Board::getInstance()->getBoardElement(LOUNGE);
    elem->setScarletLabel(m_ui->lbLoungeScarlet);
    elem->setMustardLabel(m_ui->lbLoungeMustard);
    elem->setWhiteLabel(m_ui->lbLoungeWhite);
    elem->setGreenLabel(m_ui->lbLoungeGreen);
    elem->setPeacockLabel(m_ui->lbLoungePeacock);
    elem->setPlumLabel(m_ui->lbLoungePlum);

    //gets BilliardRoom elements and sets UI
    elem = Board::getInstance()->getBoardElement(BILLIARD_ROOM);
    elem->setScarletLabel(m_ui->lbBilliardRoomScarlet);
    elem->setMustardLabel(m_ui->lbBilliardRoomMustard);
    elem->setWhiteLabel(m_ui->lbBilliardRoomWhite);
    elem->setGreenLabel(m_ui->lbBilliardRoomGreen);
    elem->setPeacockLabel(m_ui->lbBilliardRoomPeacock);
    elem->setPlumLabel(m_ui->lbBilliardRoomPlum);

    //gets Library elements and sets UI
    elem = Board::getInstance()->getBoardElement(LIBRARY);
    elem->setScarletLabel(m_ui->lbLibraryScarlet);
    elem->setMustardLabel(m_ui->lbLibraryMustard);
    elem->setWhiteLabel(m_ui->lbLibraryWhite);
    elem->setGreenLabel(m_ui->lbLibraryGreen);
    elem->setPeacockLabel(m_ui->lbLibraryPeacock);
    elem->setPlumLabel(m_ui->lbLibraryPlum);

    //gets Hall elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALL);
    elem->setScarletLabel(m_ui->lbHallScarlet);
    elem->setMustardLabel(m_ui->lbHallMustard);
    elem->setWhiteLabel(m_ui->lbHallWhite);
    elem->setGreenLabel(m_ui->lbHallGreen);
    elem->setPeacockLabel(m_ui->lbHallPeacock);
    elem->setPlumLabel(m_ui->lbHallPlum);

    //gets DiningRoom elements and sets UI
    elem = Board::getInstance()->getBoardElement(DINING_ROOM);
    elem->setScarletLabel(m_ui->lbDiningRoomScarlet);
    elem->setMustardLabel(m_ui->lbDiningRoomMustard);
    elem->setWhiteLabel(m_ui->lbDiningRoomWhite);
    elem->setGreenLabel(m_ui->lbDiningRoomGreen);
    elem->setPeacockLabel(m_ui->lbDiningRoomPeacock);
    elem->setPlumLabel(m_ui->lbDiningRoomPlum);

    //gets Conservatory elements and sets UI
    elem = Board::getInstance()->getBoardElement(CONSERVATORY);
    elem->setScarletLabel(m_ui->lbConservatoryScarlet);
    elem->setMustardLabel(m_ui->lbConservatoryMustard);
    elem->setWhiteLabel(m_ui->lbConservatoryWhite);
    elem->setGreenLabel(m_ui->lbConservatoryGreen);
    elem->setPeacockLabel(m_ui->lbConservatoryPeacock);
    elem->setPlumLabel(m_ui->lbConservatoryPlum);

    //gets Ballroom elements and sets UI
    elem = Board::getInstance()->getBoardElement(BALLROOM);
    elem->setScarletLabel(m_ui->lbBallroomScarlet);
    elem->setMustardLabel(m_ui->lbBallroomMustard);
    elem->setWhiteLabel(m_ui->lbBallroomWhite);
    elem->setGreenLabel(m_ui->lbBallroomGreen);
    elem->setPeacockLabel(m_ui->lbBallroomPeacock);
    elem->setPlumLabel(m_ui->lbBallroomPlum);

    //gets Kitchen elements and sets UI
    elem = Board::getInstance()->getBoardElement(KITCHEN);
    elem->setScarletLabel(m_ui->lbKitchenScarlet);
    elem->setMustardLabel(m_ui->lbKitchenMustard);
    elem->setWhiteLabel(m_ui->lbKitchenWhite);
    elem->setGreenLabel(m_ui->lbKitchenGreen);
    elem->setPeacockLabel(m_ui->lbKitchenPeacock);
    elem->setPlumLabel(m_ui->lbKitchenPlum);

    //gets Hallway1 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_1);
    elem->setScarletLabel(m_ui->lbHallway1Scarlet);
    elem->setMustardLabel(m_ui->lbHallway1Mustard);
    elem->setWhiteLabel(m_ui->lbHallway1White);
    elem->setGreenLabel(m_ui->lbHallway1Green);
    elem->setPeacockLabel(m_ui->lbHallway1Peacock);
    elem->setPlumLabel(m_ui->lbHallway1Plum);

    //gets Hallway2 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_2);
    elem->setScarletLabel(m_ui->lbHallway2Scarlet);
    elem->setMustardLabel(m_ui->lbHallway2Mustard);
    elem->setWhiteLabel(m_ui->lbHallway2White);
    elem->setGreenLabel(m_ui->lbHallway2Green);
    elem->setPeacockLabel(m_ui->lbHallway2Peacock);
    elem->setPlumLabel(m_ui->lbHallway2Plum);

    //gets Hallway3 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_3);
    elem->setScarletLabel(m_ui->lbHallway3Scarlet);
    elem->setMustardLabel(m_ui->lbHallway3Mustard);
    elem->setWhiteLabel(m_ui->lbHallway3White);
    elem->setGreenLabel(m_ui->lbHallway3Green);
    elem->setPeacockLabel(m_ui->lbHallway3Peacock);
    elem->setPlumLabel(m_ui->lbHallway3Plum);

    //gets Hallway4 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_4);
    elem->setScarletLabel(m_ui->lbHallway4Scarlet);
    elem->setMustardLabel(m_ui->lbHallway4Mustard);
    elem->setWhiteLabel(m_ui->lbHallway4White);
    elem->setGreenLabel(m_ui->lbHallway4Green);
    elem->setPeacockLabel(m_ui->lbHallway4Peacock);
    elem->setPlumLabel(m_ui->lbHallway4Plum);

    //gets Hallway5 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_5);
    elem->setScarletLabel(m_ui->lbHallway5Scarlet);
    elem->setMustardLabel(m_ui->lbHallway5Mustard);
    elem->setWhiteLabel(m_ui->lbHallway5White);
    elem->setGreenLabel(m_ui->lbHallway5Green);
    elem->setPeacockLabel(m_ui->lbHallway5Peacock);
    elem->setPlumLabel(m_ui->lbHallway5Plum);

    //gets Hallway6 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_6);
    elem->setScarletLabel(m_ui->lbHallway6Scarlet);
    elem->setMustardLabel(m_ui->lbHallway6Mustard);
    elem->setWhiteLabel(m_ui->lbHallway6White);
    elem->setGreenLabel(m_ui->lbHallway6Green);
    elem->setPeacockLabel(m_ui->lbHallway6Peacock);
    elem->setPlumLabel(m_ui->lbHallway6Plum);

    //gets Hallway7 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_7);
    elem->setScarletLabel(m_ui->lbHallway7Scarlet);
    elem->setMustardLabel(m_ui->lbHallway7Mustard);
    elem->setWhiteLabel(m_ui->lbHallway7White);
    elem->setGreenLabel(m_ui->lbHallway7Green);
    elem->setPeacockLabel(m_ui->lbHallway7Peacock);
    elem->setPlumLabel(m_ui->lbHallway7Plum);

    //gets Hallway8 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_8);
    elem->setScarletLabel(m_ui->lbHallway8Scarlet);
    elem->setMustardLabel(m_ui->lbHallway8Mustard);
    elem->setWhiteLabel(m_ui->lbHallway8White);
    elem->setGreenLabel(m_ui->lbHallway8Green);
    elem->setPeacockLabel(m_ui->lbHallway8Peacock);
    elem->setPlumLabel(m_ui->lbHallway8Plum);

    //gets Hallway9 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_9);
    elem->setScarletLabel(m_ui->lbHallway9Scarlet);
    elem->setMustardLabel(m_ui->lbHallway9Mustard);
    elem->setWhiteLabel(m_ui->lbHallway9White);
    elem->setGreenLabel(m_ui->lbHallway9Green);
    elem->setPeacockLabel(m_ui->lbHallway9Peacock);
    elem->setPlumLabel(m_ui->lbHallway9Plum);

    //gets Hallway10 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_10);
    elem->setScarletLabel(m_ui->lbHallway10Scarlet);
    elem->setMustardLabel(m_ui->lbHallway10Mustard);
    elem->setWhiteLabel(m_ui->lbHallway10White);
    elem->setGreenLabel(m_ui->lbHallway10Green);
    elem->setPeacockLabel(m_ui->lbHallway10Peacock);
    elem->setPlumLabel(m_ui->lbHallway10Plum);

    //gets Hallway11 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_11);
    elem->setScarletLabel(m_ui->lbHallway11Scarlet);
    elem->setMustardLabel(m_ui->lbHallway11Mustard);
    elem->setWhiteLabel(m_ui->lbHallway11White);
    elem->setGreenLabel(m_ui->lbHallway11Green);
    elem->setPeacockLabel(m_ui->lbHallway11Peacock);
    elem->setPlumLabel(m_ui->lbHallway11Plum);

    //gets Hallway12 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_12);
    elem->setScarletLabel(m_ui->lbHallway12Scarlet);
    elem->setMustardLabel(m_ui->lbHallway12Mustard);
    elem->setWhiteLabel(m_ui->lbHallway12White);
    elem->setGreenLabel(m_ui->lbHallway12Green);
    elem->setPeacockLabel(m_ui->lbHallway12Peacock);
    elem->setPlumLabel(m_ui->lbHallway12Plum);

}
