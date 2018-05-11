#include "Server.h"
#include <QDebug>
#include <QNetworkInterface>
#include <QDebug>

Server::Server(int maxPlayers, int port)
    : maxPlayers_(maxPlayers), port_(port)
{
    for (int i = 0; i < maxPlayers_; ++i)
    {
        sockets_.append(new QTcpSocket(this));
        sockets_.at(i)->setSocketOption(QAbstractSocket::LowDelayOption, 1);
        socketUsed_.append(false);
    }
    numConnected_ = 0;

    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             qDebug() << address.toString();
    }
}

Server::~Server()
{
    disconnect_all();
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    if (numConnected_ == maxPlayers_)
    {
        return;
    }
    int openSlot = 0;
    for (int i = 0; i < maxPlayers_; ++i)
    {
        if (!socketUsed_.at(i))
        {
            openSlot = i;
            break;
        }
    }
    // Socket connects in if statement.
    if (!sockets_.at(openSlot)->setSocketDescriptor(socketDescriptor))
    {
        qDebug() << sockets_.at(openSlot)->errorString();
        return;
    }

    if (openSlot == 0)
    {
        connect(sockets_.at(openSlot), SIGNAL(readyRead()),
                this, SLOT(readyRead0()),
                Qt::DirectConnection);
    }
    else if (openSlot == 1)
    {
        connect(sockets_.at(openSlot), SIGNAL(readyRead()),
                this, SLOT(readyRead1()),
                Qt::DirectConnection);
    }
    else if (openSlot == 2)
    {
        connect(sockets_.at(openSlot), SIGNAL(readyRead()),
                this, SLOT(readyRead2()),
                Qt::DirectConnection);
    }
    else if (openSlot == 3)
    {
        connect(sockets_.at(openSlot), SIGNAL(readyRead()),
                this, SLOT(readyRead3()),
                Qt::DirectConnection);
    }
    else if (openSlot == 4)
    {
        connect(sockets_.at(openSlot), SIGNAL(readyRead()),
                this, SLOT(readyRead4()),
                Qt::DirectConnection);
    }
    else
    {
        connect(sockets_.at(openSlot), SIGNAL(readyRead()),
                this, SLOT(readyRead5()),
                Qt::DirectConnection);
    }

    socketUsed_[openSlot] = true;
    ++numConnected_;
    qDebug() << "Player " << openSlot + 1 << " connected.";

    send(protocol::form_player_connect(
             protocol::PlayerConnect((PlayerEnum) openSlot)), openSlot);

    if (numConnected_ == maxPlayers_)
    {
        protocol::Initialization init;

        //sets number of connected players
        init.numConnected = numConnected_;

        //creates a generator
        mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

        //shuffles suspect cards
        QList<CardEnum> suspectList;
        suspectList.append(SCARLET_CARD);
        suspectList.append(MUSTARD_CARD);
        suspectList.append(WHITE_CARD);
        suspectList.append(GREEN_CARD);
        suspectList.append(PEACOCK_CARD);
        suspectList.append(PLUM_CARD);
        list<CardEnum> stdList1 = suspectList.toStdList();
        vector<CardEnum> V1(stdList1.begin(), stdList1.end());
        shuffle(V1.begin(), V1.end(), gen);
        stdList1.assign(V1.begin(), V1.end());
        QList<CardEnum> shuffledSuspectList =
                QList<CardEnum>::fromStdList(stdList1);

        //shuffles weapon cards
        QList<CardEnum> weaponList;
        weaponList.append(CANDLESTICK_CARD);
        weaponList.append(KNIFE_CARD);
        weaponList.append(LEAD_PIPE_CARD);
        weaponList.append(REVOLVER_CARD);
        weaponList.append(ROPE_CARD);
        weaponList.append(WRENCH_CARD);
        list<CardEnum> stdList2 = weaponList.toStdList();
        vector<CardEnum> V2(stdList2.begin(), stdList2.end());
        shuffle(V2.begin(), V2.end(), gen);
        stdList2.assign(V2.begin(), V2.end());
        QList<CardEnum> shuffledWeaponList =
                QList<CardEnum>::fromStdList(stdList2);

        //shuffs room cards
        QList<CardEnum> roomList;
        roomList.append(KITCHEN_CARD);
        roomList.append(BALLROOM_CARD);
        roomList.append(CONSERVATORY_CARD);
        roomList.append(DINING_ROOM_CARD);
        roomList.append(BILLIARD_ROOM_CARD);
        roomList.append(LIBRARY_CARD);
        roomList.append(LOUNGE_CARD);
        roomList.append(HALL_CARD);
        roomList.append(STUDY_CARD);
        list<CardEnum> stdList3 = roomList.toStdList();
        vector<CardEnum> V3(stdList3.begin(), stdList3.end());
        shuffle(V3.begin(), V3.end(), gen);
        stdList3.assign(V3.begin(), V3.end());
        QList<CardEnum> shuffledRoomList =
                QList<CardEnum>::fromStdList(stdList3);

        //sets the hidden cards
        init.hiddenSuspect = shuffledSuspectList.takeFirst();
        init.hiddenWeapon = shuffledWeaponList.takeFirst();
        init.hiddenRoom = shuffledRoomList.takeFirst();

        //adds all cards to one list
        QList<CardEnum> cardList;
        cardList.append(shuffledSuspectList);
        cardList.append(shuffledWeaponList);
        cardList.append(shuffledRoomList);

        //initializes cards options to INVALID_CARD
        init.p1Card1 = INVALID_CARD;
        init.p1Card2 = INVALID_CARD;
        init.p1Card3 = INVALID_CARD;
        init.p1Card4 = INVALID_CARD;
        init.p1Card5 = INVALID_CARD;
        init.p1Card6 = INVALID_CARD;
        init.p2Card1 = INVALID_CARD;
        init.p2Card2 = INVALID_CARD;
        init.p2Card3 = INVALID_CARD;
        init.p2Card4 = INVALID_CARD;
        init.p2Card5 = INVALID_CARD;
        init.p2Card6 = INVALID_CARD;
        init.p3Card1 = INVALID_CARD;
        init.p3Card2 = INVALID_CARD;
        init.p3Card3 = INVALID_CARD;
        init.p3Card4 = INVALID_CARD;
        init.p3Card5 = INVALID_CARD;
        init.p3Card6 = INVALID_CARD;
        init.p4Card1 = INVALID_CARD;
        init.p4Card2 = INVALID_CARD;
        init.p4Card3 = INVALID_CARD;
        init.p4Card4 = INVALID_CARD;
        init.p5Card1 = INVALID_CARD;
        init.p5Card2 = INVALID_CARD;
        init.p5Card3 = INVALID_CARD;
        init.p6Card1 = INVALID_CARD;
        init.p6Card2 = INVALID_CARD;
        init.p6Card3 = INVALID_CARD;

        //distributes cards based on number of players
        if (numConnected_ == 3)
        {
            init.p1Card1 = cardList.takeFirst();
            init.p2Card1 = cardList.takeFirst();
            init.p3Card1 = cardList.takeFirst();
            init.p1Card2 = cardList.takeFirst();
            init.p2Card2 = cardList.takeFirst();
            init.p3Card2 = cardList.takeFirst();
            init.p1Card3 = cardList.takeFirst();
            init.p2Card3 = cardList.takeFirst();
            init.p3Card3 = cardList.takeFirst();
            init.p1Card4 = cardList.takeFirst();
            init.p2Card4 = cardList.takeFirst();
            init.p3Card4 = cardList.takeFirst();
            init.p1Card5 = cardList.takeFirst();
            init.p2Card5 = cardList.takeFirst();
            init.p3Card5 = cardList.takeFirst();
            init.p1Card6 = cardList.takeFirst();
            init.p2Card6 = cardList.takeFirst();
            init.p3Card6 = cardList.takeFirst();
        }
        else if (numConnected_ == 4)
        {
            init.p1Card1 = cardList.takeFirst();
            init.p2Card1 = cardList.takeFirst();
            init.p3Card1 = cardList.takeFirst();
            init.p4Card1 = cardList.takeFirst();
            init.p1Card2 = cardList.takeFirst();
            init.p2Card2 = cardList.takeFirst();
            init.p3Card2 = cardList.takeFirst();
            init.p4Card2 = cardList.takeFirst();
            init.p1Card3 = cardList.takeFirst();
            init.p2Card3 = cardList.takeFirst();
            init.p3Card3 = cardList.takeFirst();
            init.p4Card3 = cardList.takeFirst();
            init.p1Card4 = cardList.takeFirst();
            init.p2Card4 = cardList.takeFirst();
            init.p3Card4 = cardList.takeFirst();
            init.p4Card4 = cardList.takeFirst();
            init.p1Card5 = cardList.takeFirst();
            init.p2Card5 = cardList.takeFirst();
        }
        else if (numConnected_ == 5)
        {
            init.p1Card1 = cardList.takeFirst();
            init.p2Card1 = cardList.takeFirst();
            init.p3Card1 = cardList.takeFirst();
            init.p4Card1 = cardList.takeFirst();
            init.p5Card1 = cardList.takeFirst();
            init.p1Card2 = cardList.takeFirst();
            init.p2Card2 = cardList.takeFirst();
            init.p3Card2 = cardList.takeFirst();
            init.p4Card2 = cardList.takeFirst();
            init.p5Card2 = cardList.takeFirst();
            init.p1Card3 = cardList.takeFirst();
            init.p2Card3 = cardList.takeFirst();
            init.p3Card3 = cardList.takeFirst();
            init.p4Card3 = cardList.takeFirst();
            init.p5Card3 = cardList.takeFirst();
            init.p1Card4 = cardList.takeFirst();
            init.p2Card4 = cardList.takeFirst();
            init.p3Card4 = cardList.takeFirst();
        }
        else if (numConnected_ == 6)
        {
            init.p1Card1 = cardList.takeFirst();
            init.p2Card1 = cardList.takeFirst();
            init.p3Card1 = cardList.takeFirst();
            init.p4Card1 = cardList.takeFirst();
            init.p5Card1 = cardList.takeFirst();
            init.p6Card1 = cardList.takeFirst();
            init.p1Card2 = cardList.takeFirst();
            init.p2Card2 = cardList.takeFirst();
            init.p3Card2 = cardList.takeFirst();
            init.p4Card2 = cardList.takeFirst();
            init.p5Card2 = cardList.takeFirst();
            init.p6Card2 = cardList.takeFirst();
            init.p1Card3 = cardList.takeFirst();
            init.p2Card3 = cardList.takeFirst();
            init.p3Card3 = cardList.takeFirst();
            init.p4Card3 = cardList.takeFirst();
            init.p5Card3 = cardList.takeFirst();
            init.p6Card3 = cardList.takeFirst();
        }

        send_all(protocol::form_initialization(init));
    }

}

void Server::readyRead0()
{
    while(!sockets_.at(0)->atEnd())
    {
        buffer_ = sockets_.at(0)->readAll();
        qDebug() << "Socket 0 Received " << buffer_;
        send_all(buffer_);
    }
}

void Server::readyRead1()
{
    while(!sockets_.at(1)->atEnd())
    {
        buffer_ = sockets_.at(1)->readAll();
        qDebug() << "Socket 1 Received " << buffer_;
        send_all(buffer_);
    }
}

void Server::readyRead2()
{
    while(!sockets_.at(2)->atEnd())
    {
        buffer_ = sockets_.at(2)->readAll();
        qDebug() << "Socket 2 Received " << buffer_;
        send_all(buffer_);
    }
}

void Server::readyRead3()
{
    while(!sockets_.at(3)->atEnd())
    {
        buffer_ = sockets_.at(3)->readAll();
        qDebug() << "Socket 3 Received " << buffer_;
        send_all(buffer_);
    }
}

void Server::readyRead4()
{
    while(!sockets_.at(4)->atEnd())
    {
        buffer_ = sockets_.at(4)->readAll();
        qDebug() << "Socket 4 Received " << buffer_;
        send_all(buffer_);
    }
}

void Server::readyRead5()
{
    while(!sockets_.at(5)->atEnd())
    {
        buffer_ = sockets_.at(5)->readAll();
        qDebug() << "Socket 5 Received " << buffer_;
        send_all(buffer_);
    }
}

void Server::send(QByteArray data, int playerIndex)
{
    qDebug() << "Sent " << data << " to player " << playerIndex + 1;
    sockets_.at(playerIndex)->write(data);
    sockets_.at(playerIndex)->waitForBytesWritten();
}

void Server::send_all(QByteArray data)
{
    for (int playerIndex = 0; playerIndex < maxPlayers_; ++playerIndex)
    {
        if (socketUsed_.at(playerIndex))
        {
            send(data, playerIndex);
        }
    }
}

void Server::disconnect(int playerIndex)
{
    if (socketUsed_.at(playerIndex))
    {
        sockets_.at(playerIndex)->disconnectFromHost();
        if (sockets_.at(playerIndex)->state() != QAbstractSocket::UnconnectedState)
        {
            sockets_.at(playerIndex)->waitForDisconnected();
        }
        delete(sockets_.at(playerIndex));
        sockets_[playerIndex] = new QTcpSocket(this);
        socketUsed_[playerIndex] = false;
        --numConnected_;
    }
}

void Server::disconnect_all()
{
    for (int i = 0; i < maxPlayers_; ++i)
    {
        disconnect(i);
    }
}
