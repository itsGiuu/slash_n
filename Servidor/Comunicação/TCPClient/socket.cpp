#include "socket.h"

socket::socket(QObject *parent) :
    QObject(parent)
{
}

void socket::setIP(QString IP){
    IPAddress = IP;
}

void socket::setPort(int p){
    port = p;
}

void socket::doConnect()
{
    qtsocket = new QTcpSocket(this);
    connect(qtsocket, SIGNAL(connected()),this, SLOT(connected()));
    connect(qtsocket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(qtsocket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(qtsocket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";

    qtsocket->connectToHost(IPAddress, port);
    if(!qtsocket->waitForConnected(10000))
    {
        qDebug() << "Error: " << qtsocket->errorString();

    }
}

void socket::disconnect(){
    qtsocket->disconnectFromHost();
    qDebug() << "Closed connection";
}


void socket::writeMessage(char *data){
    qtsocket->write(data);
}

void socket::writeMessage(string data){
    //Não sei se essa conversão de string -> char array precisa
    //de alocação de memória
    char *data_char = &data[0u];
    qtsocket->write(data_char);
}

void socket::connected()
{
    qDebug() << "connected...";


}

void socket::disconnected()
{
    qDebug() << "disconnected...";
}

void socket::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void socket::readyRead()
{
    qDebug() << "reading...";
    qDebug() << qtsocket->readAll();
}
