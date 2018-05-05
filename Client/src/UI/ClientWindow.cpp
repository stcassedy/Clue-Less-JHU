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
    ui(new Ui::ClientWindow),
    navigateBoardDlg(parent),
    suggestionDlg(parent),
    accusationDlg(parent),
    refutationDlg(parent),
    notebookDlg(parent)
{
    //sets up the UI
    ui->setupUi(this);
    setWindowTitle("Clue-Less");

    //defaults to start page
    ui->stackedWidget->setCurrentIndex(START_PAGE);

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
    delete ui; 
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
    ui->stackedWidget->setCurrentIndex(CHARACTER_SELECTION_PAGE);
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
    ui->stackedWidget->setCurrentIndex(GAME_BOARD_PAGE);

    //TODO: load current board state

}

void ClientWindow::on_btnAckNoServer_clicked()
{
    //show the start page
    ui->stackedWidget->setCurrentIndex(START_PAGE);
}

void ClientWindow::on_btnNavigateBoard_clicked()
{
    //shows the navigate board dialog
    navigateBoardDlg.show();
}

void ClientWindow::on_btnMakeSuggestion_clicked()
{
    //shows the suggestion dialog
    suggestionDlg.show();
}

void ClientWindow::on_btnRefute_clicked()
{
    //shows the refutation dialog
    refutationDlg.show();
}

void ClientWindow::on_btnMakeAccusation_clicked()
{
    //shows the accusation dialog
    accusationDlg.show();
}

void ClientWindow::on_btnViewNotebook_clicked()
{
    //shows the notebook dialog
    notebookDlg.show();
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
    elem->setScarletLabel(ui->lbStudyScarlet);
    elem->setMustardLabel(ui->lbStudyMustard);
    elem->setWhiteLabel(ui->lbStudyWhite);
    elem->setGreenLabel(ui->lbStudyGreen);
    elem->setPeacockLabel(ui->lbStudyPeacock);
    elem->setPlumLabel(ui->lbStudyPlum);

    //gets Lounge elements and sets UI
    elem = Board::getInstance()->getBoardElement(LOUNGE);
    elem->setScarletLabel(ui->lbLoungeScarlet);
    elem->setMustardLabel(ui->lbLoungeMustard);
    elem->setWhiteLabel(ui->lbLoungeWhite);
    elem->setGreenLabel(ui->lbLoungeGreen);
    elem->setPeacockLabel(ui->lbLoungePeacock);
    elem->setPlumLabel(ui->lbLoungePlum);

    //gets BilliardRoom elements and sets UI
    elem = Board::getInstance()->getBoardElement(BILLIARD_ROOM);
    elem->setScarletLabel(ui->lbBilliardRoomScarlet);
    elem->setMustardLabel(ui->lbBilliardRoomMustard);
    elem->setWhiteLabel(ui->lbBilliardRoomWhite);
    elem->setGreenLabel(ui->lbBilliardRoomGreen);
    elem->setPeacockLabel(ui->lbBilliardRoomPeacock);
    elem->setPlumLabel(ui->lbBilliardRoomPlum);

    //gets Library elements and sets UI
    elem = Board::getInstance()->getBoardElement(LIBRARY);
    elem->setScarletLabel(ui->lbLibraryScarlet);
    elem->setMustardLabel(ui->lbLibraryMustard);
    elem->setWhiteLabel(ui->lbLibraryWhite);
    elem->setGreenLabel(ui->lbLibraryGreen);
    elem->setPeacockLabel(ui->lbLibraryPeacock);
    elem->setPlumLabel(ui->lbLibraryPlum);

    //gets Hall elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALL);
    elem->setScarletLabel(ui->lbHallScarlet);
    elem->setMustardLabel(ui->lbHallMustard);
    elem->setWhiteLabel(ui->lbHallWhite);
    elem->setGreenLabel(ui->lbHallGreen);
    elem->setPeacockLabel(ui->lbHallPeacock);
    elem->setPlumLabel(ui->lbHallPlum);

    //gets DiningRoom elements and sets UI
    elem = Board::getInstance()->getBoardElement(DINING_ROOM);
    elem->setScarletLabel(ui->lbDiningRoomScarlet);
    elem->setMustardLabel(ui->lbDiningRoomMustard);
    elem->setWhiteLabel(ui->lbDiningRoomWhite);
    elem->setGreenLabel(ui->lbDiningRoomGreen);
    elem->setPeacockLabel(ui->lbDiningRoomPeacock);
    elem->setPlumLabel(ui->lbDiningRoomPlum);

    //gets Conservatory elements and sets UI
    elem = Board::getInstance()->getBoardElement(CONSERVATORY);
    elem->setScarletLabel(ui->lbConservatoryScarlet);
    elem->setMustardLabel(ui->lbConservatoryMustard);
    elem->setWhiteLabel(ui->lbConservatoryWhite);
    elem->setGreenLabel(ui->lbConservatoryGreen);
    elem->setPeacockLabel(ui->lbConservatoryPeacock);
    elem->setPlumLabel(ui->lbConservatoryPlum);

    //gets Ballroom elements and sets UI
    elem = Board::getInstance()->getBoardElement(BALLROOM);
    elem->setScarletLabel(ui->lbBallroomScarlet);
    elem->setMustardLabel(ui->lbBallroomMustard);
    elem->setWhiteLabel(ui->lbBallroomWhite);
    elem->setGreenLabel(ui->lbBallroomGreen);
    elem->setPeacockLabel(ui->lbBallroomPeacock);
    elem->setPlumLabel(ui->lbBallroomPlum);

    //gets Kitchen elements and sets UI
    elem = Board::getInstance()->getBoardElement(KITCHEN);
    elem->setScarletLabel(ui->lbKitchenScarlet);
    elem->setMustardLabel(ui->lbKitchenMustard);
    elem->setWhiteLabel(ui->lbKitchenWhite);
    elem->setGreenLabel(ui->lbKitchenGreen);
    elem->setPeacockLabel(ui->lbKitchenPeacock);
    elem->setPlumLabel(ui->lbKitchenPlum);

    //gets Hallway1 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_1);
    elem->setScarletLabel(ui->lbHallway1Scarlet);
    elem->setMustardLabel(ui->lbHallway1Mustard);
    elem->setWhiteLabel(ui->lbHallway1White);
    elem->setGreenLabel(ui->lbHallway1Green);
    elem->setPeacockLabel(ui->lbHallway1Peacock);
    elem->setPlumLabel(ui->lbHallway1Plum);

    //gets Hallway2 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_2);
    elem->setScarletLabel(ui->lbHallway2Scarlet);
    elem->setMustardLabel(ui->lbHallway2Mustard);
    elem->setWhiteLabel(ui->lbHallway2White);
    elem->setGreenLabel(ui->lbHallway2Green);
    elem->setPeacockLabel(ui->lbHallway2Peacock);
    elem->setPlumLabel(ui->lbHallway2Plum);

    //gets Hallway3 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_3);
    elem->setScarletLabel(ui->lbHallway3Scarlet);
    elem->setMustardLabel(ui->lbHallway3Mustard);
    elem->setWhiteLabel(ui->lbHallway3White);
    elem->setGreenLabel(ui->lbHallway3Green);
    elem->setPeacockLabel(ui->lbHallway3Peacock);
    elem->setPlumLabel(ui->lbHallway3Plum);

    //gets Hallway4 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_4);
    elem->setScarletLabel(ui->lbHallway4Scarlet);
    elem->setMustardLabel(ui->lbHallway4Mustard);
    elem->setWhiteLabel(ui->lbHallway4White);
    elem->setGreenLabel(ui->lbHallway4Green);
    elem->setPeacockLabel(ui->lbHallway4Peacock);
    elem->setPlumLabel(ui->lbHallway4Plum);

    //gets Hallway5 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_5);
    elem->setScarletLabel(ui->lbHallway5Scarlet);
    elem->setMustardLabel(ui->lbHallway5Mustard);
    elem->setWhiteLabel(ui->lbHallway5White);
    elem->setGreenLabel(ui->lbHallway5Green);
    elem->setPeacockLabel(ui->lbHallway5Peacock);
    elem->setPlumLabel(ui->lbHallway5Plum);

    //gets Hallway6 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_6);
    elem->setScarletLabel(ui->lbHallway6Scarlet);
    elem->setMustardLabel(ui->lbHallway6Mustard);
    elem->setWhiteLabel(ui->lbHallway6White);
    elem->setGreenLabel(ui->lbHallway6Green);
    elem->setPeacockLabel(ui->lbHallway6Peacock);
    elem->setPlumLabel(ui->lbHallway6Plum);

    //gets Hallway7 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_7);
    elem->setScarletLabel(ui->lbHallway7Scarlet);
    elem->setMustardLabel(ui->lbHallway7Mustard);
    elem->setWhiteLabel(ui->lbHallway7White);
    elem->setGreenLabel(ui->lbHallway7Green);
    elem->setPeacockLabel(ui->lbHallway7Peacock);
    elem->setPlumLabel(ui->lbHallway7Plum);

    //gets Hallway8 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_8);
    elem->setScarletLabel(ui->lbHallway8Scarlet);
    elem->setMustardLabel(ui->lbHallway8Mustard);
    elem->setWhiteLabel(ui->lbHallway8White);
    elem->setGreenLabel(ui->lbHallway8Green);
    elem->setPeacockLabel(ui->lbHallway8Peacock);
    elem->setPlumLabel(ui->lbHallway8Plum);

    //gets Hallway9 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_9);
    elem->setScarletLabel(ui->lbHallway9Scarlet);
    elem->setMustardLabel(ui->lbHallway9Mustard);
    elem->setWhiteLabel(ui->lbHallway9White);
    elem->setGreenLabel(ui->lbHallway9Green);
    elem->setPeacockLabel(ui->lbHallway9Peacock);
    elem->setPlumLabel(ui->lbHallway9Plum);

    //gets Hallway10 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_10);
    elem->setScarletLabel(ui->lbHallway10Scarlet);
    elem->setMustardLabel(ui->lbHallway10Mustard);
    elem->setWhiteLabel(ui->lbHallway10White);
    elem->setGreenLabel(ui->lbHallway10Green);
    elem->setPeacockLabel(ui->lbHallway10Peacock);
    elem->setPlumLabel(ui->lbHallway10Plum);

    //gets Hallway11 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_11);
    elem->setScarletLabel(ui->lbHallway11Scarlet);
    elem->setMustardLabel(ui->lbHallway11Mustard);
    elem->setWhiteLabel(ui->lbHallway11White);
    elem->setGreenLabel(ui->lbHallway11Green);
    elem->setPeacockLabel(ui->lbHallway11Peacock);
    elem->setPlumLabel(ui->lbHallway11Plum);

    //gets Hallway12 elements and sets UI
    elem = Board::getInstance()->getBoardElement(HALLWAY_12);
    elem->setScarletLabel(ui->lbHallway12Scarlet);
    elem->setMustardLabel(ui->lbHallway12Mustard);
    elem->setWhiteLabel(ui->lbHallway12White);
    elem->setGreenLabel(ui->lbHallway12Green);
    elem->setPeacockLabel(ui->lbHallway12Peacock);
    elem->setPlumLabel(ui->lbHallway12Plum);

}
