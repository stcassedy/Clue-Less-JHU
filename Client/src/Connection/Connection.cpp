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
    connect(socket_, SIGNAL(disconnected()),
            this, SLOT(connectionLost()));
    host_ = host;
    port_ = port;

    //set socket settings
    socket_->setSocketOption(QAbstractSocket::LowDelayOption, 1);
}

Connection::~Connection()
{
    //disconnects signal/slots
    disconnect(socket_, SIGNAL(readyRead()),
               this, SLOT(read()));
    disconnect(socket_, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(onError(QAbstractSocket::SocketError)));
    disconnect(socket_, SIGNAL(disconnected()),
            this, SLOT(connectionLost()));

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
        socket_->waitForBytesWritten();
    }
}

void Connection::read()
{
    //reads message from socket
    buffer_ = socket_->readAll();

    qDebug() << buffer_;

    //gets the protocol action and forwards it to the client manager for
    //processing
    QList<QByteArray> msgList = protocol::splitMessages(buffer_);
    for (int i = 0; i < msgList.size(); ++i)
    {
        protocol::Action* act = protocol::parse_message(msgList.at(i));
        ClientManager::getInstance()->processServerAction(act);
    }
}

void Connection::onError(QAbstractSocket::SocketError err)
{
    Q_UNUSED(err);
    qDebug() << "Socket Error: " << socket_->errorString();
}

void Connection::connectionLost()
{
    ClientManager::getInstance()->closeApplication();
}
