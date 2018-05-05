/**
  * @file NavigateBoardDialog.h
  */
#ifndef NAVIGATEBOARDDIALOG_H
#define NAVIGATEBOARDDIALOG_H

#include <QDialog>

//Forward Declaration
class BoardElement;

//UI namespace definition
namespace Ui {
class NavigateBoardDialog;
}

/**
 * @brief The NavigateBoardDialog class provides a UI interface for selecting
 * a board location to move to
 */
class NavigateBoardDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief NavigateBoardDialog Explicit Constructor
     * @param parent Widget*
     */
    explicit NavigateBoardDialog(QWidget *parent = 0);

    /**
     * @brief ~NavigateBoardDialog Destructor
     */
    ~NavigateBoardDialog();


public slots:
    /**
     * @brief show shows the dialog
     */
    void show();

private slots:
    /**
     * @brief on_btnStudy_clicked tells the client manager the study
     * location was selected and closes the dialog
     */
    void on_btnStudy_clicked();

    /**
     * @brief on_btnHall_clicked tells the client manager the hall
     * location was selected and closes the dialog
     */
    void on_btnHall_clicked();

    /**
     * @brief on_btnLounge_clicked tells the client manager the lounge
     * location was selected and closes the dialog
     */
    void on_btnLounge_clicked();

    /**
     * @brief on_btnLibrary_clicked tells the client manager the library
     * location was selected and closes the dialog
     */
    void on_btnLibrary_clicked();

    /**
     * @brief on_btnBilliardRoom_clicked tells the client manager the billiard
     * room location was selected and closes the dialog
     */
    void on_btnBilliardRoom_clicked();

    /**
     * @brief on_btnDiningRoom_clicked tells the client manager the dining room
     * location was selected and closes the dialog
     */
    void on_btnDiningRoom_clicked();

    /**
     * @brief on_btnConservatory_clicked tells the client manager the
     * conservatory location was selected and closes the dialog
     */
    void on_btnConservatory_clicked();

    /**
     * @brief on_btnBallroom_clicked tells the client manager the ballroom
     * location was selected and closes the dialog
     */
    void on_btnBallroom_clicked();

    /**
     * @brief on_btnKitchen_clicked tells the client manager the kitchen
     * location was selected and closes the dialog
     */
    void on_btnKitchen_clicked();

    /**
     * @brief on_btnHallway1_clicked tells the client manager the hallway 1
     * location was selected and closes the dialog
     */
    void on_btnHallway1_clicked();

    /**
     * @brief on_btnHallway2_clicked tells the client manager the hallway 2
     * location was selected and closes the dialog
     */
    void on_btnHallway2_clicked();

    /**
     * @brief on_btnHallway3_clicked tells the client manager the hallway 3
     * location was selected and closes the dialog
     */
    void on_btnHallway3_clicked();

    /**
     * @brief on_btnHallway4_clicked tells the client manager the hallway 4
     * location was selected and closes the dialog
     */
    void on_btnHallway4_clicked();

    /**
     * @brief on_btnHallway5_clicked tells the client manager the hallway 5
     * location was selected and closes the dialog
     */
    void on_btnHallway5_clicked();

    /**
     * @brief on_btnHallway6_clicked tells the client manager the hallway 6
     * location was selected and closes the dialog
     */
    void on_btnHallway6_clicked();

    /**
     * @brief on_btnHallway7_clicked tells the client manager the hallway 7
     * location was selected and closes the dialog
     */
    void on_btnHallway7_clicked();

    /**
     * @brief on_btnHallway8_clicked tells the client manager the hallway 8
     * location was selected and closes the dialog
     */
    void on_btnHallway8_clicked();

    /**
     * @brief on_btnHallway9_clicked tells the client manager the hallway 9
     * location was selected and closes the dialog
     */
    void on_btnHallway9_clicked();

    /**
     * @brief on_btnHallway10_clicked tells the client manager the hallway 10
     * location was selected and closes the dialog
     */
    void on_btnHallway10_clicked();

    /**
     * @brief on_btnHallway11_clicked tells the client manager the hallway 11
     * location was selected and closes the dialog
     */
    void on_btnHallway11_clicked();

    /**
     * @brief on_btnHallway12_clicked tells the client manager the hallway 12
     * location was selected and closes the dialog
     */
    void on_btnHallway12_clicked();

    /**
     * @brief on_btnCancel_clicked closes the dialog
     */
    void on_btnCancel_clicked();

private:
    /**
     * @brief studyIsValid determines if the study is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool studyIsValid();

    /**
     * @brief hallIsValid determines if the hall is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallIsValid();

    /**
     * @brief loungeIsValid determines if the lounge is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool loungeIsValid();

    /**
     * @brief libraryIsValid determines if the library is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool libraryIsValid();

    /**
     * @brief billiardRoomIsValid determines if the billiard room is a valid
     * move
     * @return bool true if move is valid, false otherwise
     */
    bool billiardRoomIsValid();

    /**
     * @brief diningRoomIsValid determines if the dining room is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool diningRoomIsValid();

    /**
     * @brief conservatoryIsValid determines if the conservatory is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool conservatoryIsValid();

    /**
     * @brief ballroomIsValid determines if the ballroom is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool ballroomIsValid();

    /**
     * @brief kitchenIsValid determines if the kitchen is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool kitchenIsValid();

    /**
     * @brief hallway1IsValid determines if the hallway 1 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway1IsValid();

    /**
     * @brief hallway2IsValid determines if the hallway 2 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway2IsValid();

    /**
     * @brief hallway3IsValid determines if the hallway 3 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway3IsValid();

    /**
     * @brief hallway4IsValid determines if the hallway 4 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway4IsValid();

    /**
     * @brief hallway5IsValid determines if the hallway 5 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway5IsValid();

    /**
     * @brief hallway6IsValid determines if the hallway 6 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway6IsValid();

    /**
     * @brief hallway7IsValid determines if the hallway 7 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway7IsValid();

    /**
     * @brief hallway8IsValid determines if the hallway 8 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway8IsValid();

    /**
     * @brief hallway9IsValid determines if the hallway 9 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway9IsValid();

    /**
     * @brief hallway10IsValid determines if the hallway 10 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway10IsValid();

    /**
     * @brief hallway11IsValid determines if the hallway 11 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway11IsValid();

    /**
     * @brief hallway12IsValid determines if the hallway 12 is a valid move
     * @return bool true if move is valid, false otherwise
     */
    bool hallway12IsValid();

    /**
     * @brief isValidMove checks if a board element is a valid move
     * @param elem BoardElement*
     * @return bool true if valid move, false otherwise
     */
    bool isValidMove(BoardElement* elem);

    //member variables
    Ui::NavigateBoardDialog *m_ui;

};

#endif // NAVIGATEBOARDDIALOG_H
