#include "ServerManager.h"

ServerManager::ServerManager(int numPlayers) : numPlayers_(numPlayers)
{
    server_ = new Server;
}
