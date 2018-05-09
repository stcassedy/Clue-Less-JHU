#ifndef SERVER_H
#define SERVER_H

#include <QDataStream>
#include <QTcpSocket>
#include <QTcpServer>
#include <QVector>
#include <stdlib.h>
#include <ServerProtocol.h>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(int maxPlayers);
    void send(QByteArray data, int playerIndex);
    void send_all(QByteArray data);
    int read_sockets();
    QByteArray get_buffer() {return buffer_;}
    void disconnect(int playerIndex);
    void disconnect_all();
    int num_connected() {return numConnected_;}

signals:
    void error(QTcpSocket::SocketError socketError);

public slots:
    void readyRead();

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
