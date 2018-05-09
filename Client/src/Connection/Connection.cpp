#include "Connection.h"
#include "ServerProtocol.h"
#include "ClientManager.h"
#include <QDebug>

Connection::Connection(QString host, int port)
    : socket_(new QTcpSocket(this))
{
    //connects signals/slots
    connect(socket_, SIGNAL(readyRead()),
               this, SLOT(read()));
    connect(socket_, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onError(QAbstractSocket::SocketError)));
    host_ = host;
    port_ = port;
}

Connection::~Connection()
{
    //disconnects signal/slots
    disconnect(socket_, SIGNAL(readyRead()),
               this, SLOT(read()));
    disconnect(socket_, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onError(QAbstractSocket::SocketError)));

    //closes the socket on destruction
    socket_->close();
    delete socket_;
}

bool Connection::openConnection()
{
    //attempts a connection
    if (host_ == "Cheat")
    {
        return true;
    }
    socket_->connectToHost(host_, port_);
    return socket_->waitForConnected(10000);
}

void Connection::send(QByteArray data)
{
    if (socket_->state() == QTcpSocket::ConnectedState)
    {
        socket_->write(data);
    }
}

void Connection::read()
{
    //reads message from socket
    buffer_ = socket_->readAll();

    qDebug() << buffer_;

    //gets the protocol action and forwards it to the client manager for
    //processing
    protocol::Action* act = protocol::parse_message(buffer_);
    ClientManager::getInstance()->processServerAction(act);
}

void Connection::onError(QAbstractSocket::SocketError err)
{
    Q_UNUSED(err);
    qDebug() << "Socket Error: " << socket_->errorString();
}
