#include "ClientWindow.h"
#include "ui_ClientWindow.h"
#include "NavigateBoard.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    ui->Ballroom->setText("BALLROOM\n");
    ui->BilliardRoom->setText("BILLIARD ROOM\n");
    ui->Conservatory->setText("CONSERVATORY\n");
    ui->DiningRoom->setText("DINING ROOM\n");
    ui->Hall->setText("HALL\n");
    ui->Kitchen->setText("KITCHEN\n");
    ui->Library->setText("LIBRARY\n");
    ui->Lounge->setText("LOUNGE\n");
    ui->Study->setText("STUDY\n");
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_NavigateBoard_clicked()
{
    ui->GameActions->setText("You clicked\nNavigateBoard");
    QString content = ui->Conservatory->toPlainText();
    bool isInRoom = content.contains("Colonel Mustard");
    if ( !isInRoom )
    {
        ui->Conservatory->setText(content + "Colonel Mustard");
    }
    NavigateBoard navWindow;
    navWindow.exec();
}

void ClientWindow::on_MakeSuggestion_clicked()
{
    ui->GameActions->setText("You clicked\nMake Suggestion");
}

void ClientWindow::on_Refute_clicked()
{
    ui->GameActions->setText("You clicked\nRefute");
}

void ClientWindow::on_MakeAccusation_clicked()
{
    ui->GameActions->setText("You clicked\nMake Accusation");
}

void ClientWindow::on_ViewNotebook_clicked()
{
    ui->GameActions->setText("You clicked\nView Notebook");
}

void ClientWindow::on_EndTurn_clicked()
{
    ui->GameActions->setText("You clicked\nEnd Turn");
}
