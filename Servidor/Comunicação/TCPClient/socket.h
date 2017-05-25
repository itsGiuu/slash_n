#ifndef SOCKET_H
#define SOCKET_H



#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <iostream>
#include <string>

using namespace std;

class socket : public QObject
{
    Q_OBJECT
public:
    explicit socket(QObject *parent = 0);

    void doConnect();
    void disconnect();
    void writeMessage(char *data);
    void writeMessage(string data);
    void setIP(QString IP);
    void setPort(int p);

signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();


private:
    QTcpSocket *qtsocket;
    QString IPAddress;
    int port;

};



#endif // SOCKET_H
