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
#include "NotebookDialog.h"

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

    /**
     * @brief updateUI updates the UI based on the current board state
     */
    void updateUI();

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

private:
    /**
     * @brief hideAllPlayerLabels hides all of the player labels
     */
    void hideAllPlayerLabels();

    /**
     * @brief updateScarletLocation updates Miss Scarlet's Location
     */
    void updateScarletLocation();

    /**
     * @brief updateMustardLocation updates Col. Mustard's Location
     */
    void updateMustardLocation();

    /**
     * @brief updateWhiteLocation updates Mrs. White's Location
     */
    void updateWhiteLocation();

    /**
     * @brief updateGreenLocation updates Mr. Green's Location
     */
    void updateGreenLocation();

    /**
     * @brief updatePeacockLocation updates Mrs. Peacock's Location
     */
    void updatePeacockLocation();

    /**
     * @brief updatePlumLocation updates Prof. Plum's Location
     */
    void updatePlumLocation();

    /**
     * @brief updateBoardElementUI sets pointers to UI elements in the
     * BoardElement objects
     */
    void updateBoardElementUI();

    //Member Variables
    Ui::ClientWindow *ui;
    NavigateBoardDialog navigateBoardDlg;
    SuggestionDialog suggestionDlg;
    AccusationDialog accusationDlg;
    RefutationDialog refutationDlg;
    NotebookDialog notebookDlg;
};

#endif // CLIENTWINDOW_H
