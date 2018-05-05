#ifndef SERVER_H
#define SERVER_H

#include <QDataStream>
#include <QTcpSocket>
#include <QTcpServer>
#include <stdlib.h>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    void send(QString data, int playerIndex);
    void send_all(QString data);
    int read_sockets();
    void disconnect(int playerIndex);

signals:
    void error(QTcpSocket::SocketError socketError);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QTcpSocket * sockets_[6];
    bool socketUsed_[6] {};
    QByteArray buffer_;

};

#endif // SERVER_H
