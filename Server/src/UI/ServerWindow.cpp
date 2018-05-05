/**
  * @file ServerWindow.cpp
  */
#include "ServerWindow.h"
#include "ui_ServerWindow.h"

// -----------------------------------------------------------------------------
// Constructor:
ServerWindow::ServerWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::ServerWindow)
{
    //sets up the UI
    m_ui->setupUi(this);
    setWindowTitle("Clue-Less Server");
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint);
}

// -----------------------------------------------------------------------------
// Destructor:
ServerWindow::~ServerWindow()
{
    delete m_ui;
}

// -----------------------------------------------------------------------------
// Private Slots:
void ServerWindow::on_serverStartStop_toggled(bool checked)
{
    //Determines the state of the start/stop button
    if (checked)
    {
        //Button is toggled to checked so start the server
        //TODO: Start Server
        m_ui->serverStartStop->setText("Stop");
        m_ui->numPlayers->setDisabled(true);
    }
    else
    {
        //Button is toggled to not checked so stop the server
        //TODO: Stop Server
        m_ui->serverStartStop->setText("Start");
        m_ui->numPlayers->setDisabled(false);
    }
}

void ServerWindow::on_numPlayers_valueChanged(int value)
{
    //TODO: Change numPlayers in ServerManager
}
