#ifndef SERVER_H
#define SERVER_H

#include <QDataStream>
#include <QTcpSocket>
#include <QTcpServer>
#include <QVector>
#include <stdlib.h>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(int maxPlayers);
    void send(QString data, int playerIndex);
    void send_all(QString data);
    int read_sockets();
    void disconnect(int playerIndex);
    int num_connected() {return numConnected_;}

signals:
    void error(QTcpSocket::SocketError socketError);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QVector<QTcpSocket*> sockets_;
    QVector<bool> socketUsed_;
    int numConnected_;
    int maxPlayers_;
    QByteArray buffer_;

};

#endif // SERVER_H
