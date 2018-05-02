/**
  * @file ClientWindow.h
  */
#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include "NavigateBoardDialog.h"
#include "SuggestionDialog.h"
#include "AccusationDialog.h"
#include "RefutationDialog.h"

//UI namespace definition
namespace Ui {
class ClientWindow;
}

/**
 * @brief The ClientWindow class creates the main UI components
 * and handles the user input
 */
class ClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief ClientWindow Explicit Constructor
     * @param parent QWidget*
     */
    explicit ClientWindow(QWidget *parent = 0);

    /**
      * @brief ~ClientWindow Destructor
      */
    ~ClientWindow();

private slots:
    /**
     * @brief on_btnJoinGame_clicked handles the join button being clicked
     */
    void on_btnJoinGame_clicked();

    /**
     * @brief on_btnStartGame_clicked handles the start game button being
     * clicked
     */
    void on_btnStartGame_clicked();

    /**
     * @brief on_btnAckNoServer_clicked handles the No Server Connection OK
     * button being clicked
     */
    void on_btnAckNoServer_clicked();

    /**
     * @brief on_btnReadyPlayer1_clicked handles the ready button for player 1
     * being clicked
     */
    void on_btnReadyPlayer1_clicked();

    /**
     * @brief on_btnReadyPlayer2_clicked handles the ready button for player 2
     * being clicked
     */
    void on_btnReadyPlayer2_clicked();

    /**
     * @brief on_btnReadyPlayer3_clicked handles the ready button for player 3
     * being clicked
     */
    void on_btnReadyPlayer3_clicked();

    /**
     * @brief on_btnReadyPlayer4_clicked handles the ready button for player 4
     * being clicked
     */
    void on_btnReadyPlayer4_clicked();

    /**
     * @brief on_btnReadyPlayer5_clicked handles the ready button for player 5
     * being clicked
     */
    void on_btnReadyPlayer5_clicked();

    /**
     * @brief on_btnReadyPlayer6_clicked handles the ready button for player 6
     * being clicked
     */
    void on_btnReadyPlayer6_clicked();

    /**
     * @brief on_btnNavigateBoard_clicked shows the board navigation dialog
     */
    void on_btnNavigateBoard_clicked();

    /**
     * @brief on_btnMakeSuggestion_clicked shows the suggestion dialog
     */
    void on_btnMakeSuggestion_clicked();

    /**
     * @brief on_btnRefute_clicked shows the refutation dialog
     */
    void on_btnRefute_clicked();

    /**
     * @brief on_btnMakeAccusation_clicked shows the accusation dialog
     */
    void on_btnMakeAccusation_clicked();

    /**
     * @brief on_btnViewNotebook_clicked shows the notebook dialog
     */
    void on_btnViewNotebook_clicked();

    /**
     * @brief on_btnSendChat_clicked shows the chat dialog
     */
    void on_btnSendChat_clicked();

private:
    //Member Variables
    Ui::ClientWindow *ui;
    NavigateBoardDialog navigateBoardDlg;
    SuggestionDialog suggestionDlg;
    AccusationDialog accusationDlg;
    RefutationDialog refutationDlg;
};

#endif // CLIENTWINDOW_H