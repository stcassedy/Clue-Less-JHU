#include "ClientWindow.h"
#include "ui_ClientWindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    ui->Ballroom->setText("BALLROOM");
    ui->BilliardRoom->setText("BILLIARD ROOM");
    ui->Conservatory->setText("CONSERVATORY");
    ui->DiningRoom->setText("DINING ROOM");
    ui->Hall->setText("HALL");
    ui->Kitchen->setText("KITCHEN");
    ui->Library->setText("LIBRARY");
    ui->Lounge->setText("LOUNGE");
    ui->Study->setText("STUDY");
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_NavigateBoard_clicked()
{
    ui->GameActions->setText("You clicked\nNavigateBoard");
    QString content = ui->Conservatory->toPlainText();
    ui->Conservatory->setText(content + "\nColonel Mustard\nRope");
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
