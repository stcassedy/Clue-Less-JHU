#include "Server.h"

Server::Server(int maxPlayers) : maxPlayers_(maxPlayers)
{
    for (int i = 0; i < maxPlayers_; ++i)
    {
        sockets_.append(new QTcpSocket(this));
        socketUsed_.append(false);
    }
    numConnected_ = 0;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    if (numConnected_ == maxPlayers_)
    {
        return;
    }
    int openSlot = 0;
    for (int i = 0; i < maxPlayers_; ++i)
    {
        if (!socketUsed_[i])
        {
            openSlot = i;
            break;
        }
    }
    if (!sockets_[openSlot]->setSocketDescriptor(socketDescriptor))
    {
        emit error(sockets_[openSlot]->error());
        return;
    }
    socketUsed_[openSlot] = true;
    ++numConnected_;

}

void Server::send(QString data, int playerIndex)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << data;
    sockets_[playerIndex]->write(block);
}

void Server::send_all(QString data)
{
    for (int playerIndex = 0; playerIndex < maxPlayers_; ++playerIndex)
    {
        if (socketUsed_[playerIndex])
        {
            send(data, playerIndex);
        }
    }
}

int Server::read_sockets()
{
    for (int playerIndex = 0; playerIndex < maxPlayers_; ++playerIndex)
    {
        if (!socketUsed_[playerIndex])
        {
            continue;
        }

        buffer_ = sockets_[playerIndex]->readAll();
        if (buffer_.size() == 0)
        {
            continue;
        }

        return playerIndex;
    }

    // No messages
    return -1;
}

void Server::disconnect(int playerIndex)
{
    sockets_[playerIndex]->disconnectFromHost();
    sockets_[playerIndex]->waitForDisconnected();
    socketUsed_[playerIndex] = false;
    --numConnected_;
}
