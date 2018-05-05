#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDataStream>
#include <QDialog>
#include <QTcpSocket>
#include <QtNetwork>

class Connection : public QDialog
{
    Q_OBJECT

public:
    Connection(QString host, int port);
    void send(QString data);
    void read();
    QByteArray get_buffer() {return buffer_;}

private:
    QTcpSocket *socket_ = nullptr;
    QByteArray buffer_;
};

#endif // CONNECTION_H
