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
    refutationDlg(parent),
    notebookDlg(parent)
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

void ClientWindow::on_btnSendChat_clicked()
{
    //shows the chat dialog

}
