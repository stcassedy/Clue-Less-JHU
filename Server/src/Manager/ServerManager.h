#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <Server.h>
#include <Board.h>
#include <ServerWindow.h>
#include <ServerProtocol.h>
#include <QEventLoop>

class ServerWindow;

class ServerManager
{
public:
    static ServerManager* start_server_manager(int numPlayers);

    static ServerManager* get_instance() {return &instance_;}

    static void set_window_pointer(ServerWindow * serverWindow);

    void stop();

private:
    ServerManager(int numPlayers = 0); // This constructor should continue until victory or end.
    void wait_for_players();

    int numPlayers_;
    Server * server_;
    Board * board_;
    static ServerManager instance_;
    static ServerWindow * window_;
};

#endif // SERVERMANAGER_H
