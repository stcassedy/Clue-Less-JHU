#include "Connection.h"

Connection::Connection(QString host, int port)
    : socket_(new QTcpSocket(this))
{
    connect(socket_, SIGNAL(readyRead()), SLOT(readTcpData()));
    socket_->connectToHost(host, port);

}

void Connection::send(QString data)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << data;
    socket_->write(block);
}

void Connection::read()
{
    buffer_ = socket_->readAll();
}
