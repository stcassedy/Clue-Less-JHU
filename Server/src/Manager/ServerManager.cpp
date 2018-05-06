#include "ServerManager.h"

ServerManager::ServerManager(int numPlayers) : numPlayers_(numPlayers)
{
    server_ = new Server(numPlayers);
    board_ = Board::remakeInstance();
}

ServerManager* ServerManager::start_server_manager(int numPlayers)
{
    instance_ = ServerManager::ServerManager(numPlayers);
    return &instance_;
}
