#include "ServerManager.h"

//---------------------------------------------------------------
//Static Variables:

ServerManager ServerManager::instance_;

ServerWindow * ServerManager::window_ = NULL;

ServerManager::ServerManager(int numPlayers) : numPlayers_(numPlayers)
{
    if (numPlayers_ == 0)
    {
        return;
    }
    server_ = new Server(numPlayers);
    server_->listen();
    window_->Notify(QString("Server started with %1 players.").arg(numPlayers_));
    window_->setAddress(server_->serverAddress().toString());
    window_->setPort(QString("%1").arg(server_->serverPort()));
    board_ = Board::remakeInstance();
}

void ServerManager::new_message(QByteArray data)
{
    server_->send_all(data);
}

ServerManager* ServerManager::start_server_manager(int numPlayers)
{
    instance_ = ServerManager(numPlayers);
    return &instance_;
}

void ServerManager::set_window_pointer(ServerWindow * serverWindow)
{
    window_ = serverWindow;
}

void ServerManager::stop()
{
    server_->disconnect_all();
    window_->Notify("Disconnected.");
}
