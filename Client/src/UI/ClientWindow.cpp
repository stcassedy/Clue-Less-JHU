#include "ClientWindow.h"
#include "ui_ClientWindow.h"

ClientWindow::ClientWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
}

ClientWindow::~ClientWindow()
{
    delete ui;
}

void ClientWindow::on_NavigateBoard_clicked()
{
    ui->GameActions->setText("You clicked\nNavigateBoard");
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
