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
    ~Connection();
    void send(QByteArray data);
    QByteArray get_buffer() {return buffer_;}
    bool openConnection();
    QString errorString() {return socket_->errorString();}

private slots:
    void error(QAbstractSocket::SocketError err);
    void read();

private:
    QTcpSocket *socket_ = nullptr;
    QByteArray buffer_;
    QString host_;
    int port_;
};

#endif // CONNECTION_H
