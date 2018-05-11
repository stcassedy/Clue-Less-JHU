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
    Server(int maxPlayers, int port);
    ~Server();
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
    void readyRead0();
    void readyRead1();
    void readyRead2();
    void readyRead3();
    void readyRead4();
    void readyRead5();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QVector<QTcpSocket*> sockets_;
    QVector<bool> socketUsed_;
    qint8 numConnected_;
    qint8 maxPlayers_;
    QByteArray buffer_;

    int port_;
};

#endif // SERVER_H
