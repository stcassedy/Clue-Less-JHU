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
            this, SLOT(error(QAbstractSocket::SocketError)));
    host_ = host;
    port_ = port;
}

Connection::~Connection()
{
    //disconnects signal/slots
    disconnect(socket_, SIGNAL(readyRead()),
               this, SLOT(read()));
    disconnect(socket_, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(error(QAbstractSocket::SocketError)));

    //closes the socket on destruction
    socket_->close();
    delete socket_;
}

bool Connection::openConnection()
{
    //attempts a connection
    socket_->connectToHost(host_, port_);
    return socket_->waitForConnected(1000);
}

void Connection::send(QString data)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << data;

    if (socket_->state() == QAbstractSocket::ConnectedState)
    {
        socket_->write(block);
    }
}

void Connection::read()
{
    //reads message from socket
    buffer_ = socket_->readAll();

    //gets the protocol action and forwards it to the client manager for
    //processing
    protocol::Action* act = protocol::parse_message(buffer_);
    ClientManager::getInstance()->processServerAction(act);
}

void Connection::error(QAbstractSocket::SocketError err)
{
    Q_UNUSED(err);
    qDebug() << "Socket Error: " << socket_->errorString();
}
