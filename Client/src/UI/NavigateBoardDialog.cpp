/**
  * @file NavigateBoardDialog.cpp
  */
#include "NavigateBoardDialog.h"
#include "ui_NavigateBoardDialog.h"
#include "Board.h"

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
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHall_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnLounge_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnLibrary_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnBilliardRoom_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnDiningRoom_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnConservatory_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnBallroom_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnKitchen_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway1_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway2_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway3_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway4_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway5_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway6_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway7_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway8_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway9_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway10_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway11_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnHallway12_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

void NavigateBoardDialog::on_btnCancel_clicked()
{
    //TODO: tells client manager of the selected move

    //closes the dialog
    close();
}

// -----------------------------------------------------------------------------
// Private Functions:
bool NavigateBoardDialog::studyIsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallIsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::loungeIsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::libraryIsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::billiardRoomIsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::diningRoomIsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::conservatoryIsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::ballroomIsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::kitchenIsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway1IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway2IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway3IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway4IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway5IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway6IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway7IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway8IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway9IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway10IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway11IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}

bool NavigateBoardDialog::hallway12IsValid()
{
    //tracks if the move is valid
    bool valid = false;

    //TODO: determine if the move is valid for the player

    return valid;
}
