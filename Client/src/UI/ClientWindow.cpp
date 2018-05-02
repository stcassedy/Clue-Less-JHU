/**
 * @file ClientWindow.cpp
 */
#include "ClientWindow.h"
#include "ui_ClientWindow.h"

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
    refutationDlg(parent)
{
    //sets up the UI
    ui->setupUi(this);
    setWindowTitle("Clue-Less");

    //defaults to start page
    ui->stackedWidget->setCurrentIndex(START_PAGE);
}

// -----------------------------------------------------------------------------
// Destructor:
ClientWindow::~ClientWindow()
{
    delete ui; 
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

    //Prepares the selection widgets
//    ui->lbReadyPlayer1->setText(NOT_READY_TEXT);
//    ui->btnReadyPlayer1->setDisabled(true);
//    ui->cbSelectionPlayer1->setDisabled(true);
    ui->lbReadyPlayer2->setText(NOT_READY_TEXT);
    ui->btnReadyPlayer2->setDisabled(true);
    ui->cbSelectionPlayer2->setDisabled(true);
    ui->lbReadyPlayer3->setText(NOT_READY_TEXT);
    ui->btnReadyPlayer3->setDisabled(true);
    ui->cbSelectionPlayer3->setDisabled(true);
    ui->lbReadyPlayer4->setText(NOT_READY_TEXT);
    ui->btnReadyPlayer4->setDisabled(true);
    ui->cbSelectionPlayer4->setDisabled(true);
    ui->lbReadyPlayer5->setText(NOT_READY_TEXT);
    ui->btnReadyPlayer5->setDisabled(true);
    ui->cbSelectionPlayer5->setDisabled(true);
    ui->lbReadyPlayer6->setText(NOT_READY_TEXT);
    ui->btnReadyPlayer6->setDisabled(true);
    ui->cbSelectionPlayer6->setDisabled(true);
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

void ClientWindow::on_btnReadyPlayer1_clicked()
{
    //updates the player ready status
    ui->lbReadyPlayer1->setText(READY_TEXT);
    ui->btnReadyPlayer1->setDisabled(true);
    ui->cbSelectionPlayer1->setDisabled(true);

    //TODO: set player character in client and server
}

void ClientWindow::on_btnReadyPlayer2_clicked()
{
    //updates the player ready status
    ui->lbReadyPlayer2->setText(READY_TEXT);
    ui->btnReadyPlayer2->setDisabled(true);
    ui->cbSelectionPlayer2->setDisabled(true);

    //TODO: set player character in client and server
}

void ClientWindow::on_btnReadyPlayer3_clicked()
{
    //updates the player ready status
    ui->lbReadyPlayer3->setText(READY_TEXT);
    ui->btnReadyPlayer3->setDisabled(true);
    ui->cbSelectionPlayer3->setDisabled(true);

    //TODO: set player character in client and server
}

void ClientWindow::on_btnReadyPlayer4_clicked()
{
    //updates the player ready status
    ui->lbReadyPlayer4->setText(READY_TEXT);
    ui->btnReadyPlayer4->setDisabled(true);
    ui->cbSelectionPlayer4->setDisabled(true);

    //TODO: set player character in client and server
}

void ClientWindow::on_btnReadyPlayer5_clicked()
{
    //updates the player ready status
    ui->lbReadyPlayer5->setText(READY_TEXT);
    ui->btnReadyPlayer5->setDisabled(true);
    ui->cbSelectionPlayer5->setDisabled(true);

    //TODO: set player character in client and server
}

void ClientWindow::on_btnReadyPlayer6_clicked()
{
    //updates the player ready status
    ui->lbReadyPlayer6->setText(READY_TEXT);
    ui->btnReadyPlayer6->setDisabled(true);
    ui->cbSelectionPlayer6->setDisabled(true);

    //TODO: set player character in client and server
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

}

void ClientWindow::on_btnSendChat_clicked()
{
    //shows the chat dialog

}
