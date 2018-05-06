#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <Server.h>

class ServerManager
{
public:
    ServerManager(int numPlayers);

    static ServerManager* getInstance();

private:
    int numPlayers_;
    Server * server_;
    static ServerManager instance;
};

#endif // SERVERMANAGER_H
