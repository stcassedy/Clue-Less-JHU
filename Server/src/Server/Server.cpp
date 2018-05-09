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
    // Socket connects in if statement.
    if (!sockets_[openSlot]->setSocketDescriptor(socketDescriptor))
    {
        emit error(sockets_[openSlot]->error());
        return;
    }

    connect(sockets_[openSlot], SIGNAL(QTcpSocket::readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);

    socketUsed_[openSlot] = true;
    ++numConnected_;

    emit new_message(protocol::form_player_connect(protocol::PlayerConnect((PlayerEnum) openSlot)));

    if (numConnected_ == maxPlayers_)
    {
        close();
    }

}

void Server::readyRead()
{
    read_sockets();
    emit new_message(buffer_);
}

void Server::send(QByteArray data, int playerIndex)
{
    sockets_[playerIndex]->write(data);
}

void Server::send_all(QByteArray data)
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
    if (socketUsed_[playerIndex])
    {
        sockets_[playerIndex]->disconnectFromHost();
        sockets_[playerIndex]->waitForDisconnected();
        socketUsed_[playerIndex] = false;
        --numConnected_;
    }
}

void Server::disconnect_all()
{
    for (int i = 0; i < maxPlayers_; ++i)
    {
        disconnect(i);
    }
}
