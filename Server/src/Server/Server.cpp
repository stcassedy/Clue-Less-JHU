#include "Server.h"
#include <QDebug>
#include <QNetworkInterface>

Server::Server(int maxPlayers) : maxPlayers_(maxPlayers)
{
    for (int i = 0; i < maxPlayers_; ++i)
    {
        sockets_.append(new QTcpSocket(this));
        socketUsed_.append(false);
    }
    numConnected_ = 0;

    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             qDebug() << address.toString();
    }
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
    qDebug() << "Player " << openSlot + 1 << " connected.";

    send_all(protocol::form_player_connect(protocol::PlayerConnect((PlayerEnum) openSlot)));

    if (numConnected_ == maxPlayers_)
    {
        close();
        send_all(protocol::form_initialization(protocol::Initialization()));
    }

}

void Server::readyRead()
{
    read_sockets();
    qDebug() << "Received " << buffer_;
    send_all(buffer_);
}

void Server::send(QByteArray data, int playerIndex)
{
    qDebug() << "Sent " << data << " to player " << playerIndex + 1;
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
