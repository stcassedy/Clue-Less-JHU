#include "Server.h"

Server::Server()
{
    for (int i = 0; i < 6; ++i)
    {
        sockets_[i] = new QTcpSocket(this);
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    int openSlot = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (!socketUsed_[i])
        {
            openSlot = i;
            break;
        }
        if (i == 5)
        {
            return;
        }
    }

    if (!sockets_[openSlot]->setSocketDescriptor(socketDescriptor))
    {
        emit error(sockets_[openSlot]->error());
        return;
    }
    socketUsed_[openSlot] = true;

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
    for (int playerIndex = 0; playerIndex < 6; ++playerIndex)
    {
        if (socketUsed_[playerIndex])
        {
            send(data, playerIndex);
        }
    }
}

int Server::read_sockets()
{
    for (int playerIndex = 0; playerIndex < 6; ++playerIndex)
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
}
