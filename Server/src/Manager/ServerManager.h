#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <Server.h>
#include <Board.h>

class ServerManager
{
public:
    static ServerManager* start_server_manager(int numPlayers);

    static ServerManager* get_instance() {return &instance_;}

private:
    ServerManager(int numPlayers); // This constructor should continue until victory or end.
    void wait_for_players();

    int numPlayers_;
    Server * server_;
    Board * board_;
    static ServerManager instance_;
};

#endif // SERVERMANAGER_H
