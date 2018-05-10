#include "ServerManager.h"

//---------------------------------------------------------------
//Static Variables:

ServerManager* ServerManager::instance_ = NULL;

ServerWindow * ServerManager::window_ = NULL;

ServerManager::ServerManager(int numPlayers) : numPlayers_(numPlayers)
{
    if (numPlayers_ == 0)
    {
        return;
    }
    // TODO make change-able
    server_ = new Server(numPlayers, 53635);
    server_->listen(QHostAddress::Any, 53635);
    if (server_->isListening())
    {
        qDebug() << "listening";
    }
    window_->Notify(QString("Server started with %1 players.").arg(numPlayers_));
    window_->setAddress(server_->serverAddress().toString());
    window_->setPort(QString("%1").arg(server_->serverPort()));
    board_ = Board::remakeInstance();
    protocol::form_initialization(protocol::Initialization());
}

ServerManager* ServerManager::start_server_manager(int numPlayers)
{
    instance_ = new ServerManager(numPlayers);
    return instance_;
}

void ServerManager::set_window_pointer(ServerWindow * serverWindow)
{
    window_ = serverWindow;
}

void ServerManager::stop()
{
    delete(server_);
    window_->Notify("Disconnected.");
}

void ServerManager::init()
{
    instance_ = new ServerManager();
}

void ServerManager::destroy()
{
    delete instance_;
}
