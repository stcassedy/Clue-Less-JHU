#include "NavigateBoard.h"
#include "ui_NavigateBoard.h"

NavigateBoard::NavigateBoard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NavigateBoard)
{
    ui->setupUi(this);
}

NavigateBoard::~NavigateBoard()
{
    delete ui;
}
