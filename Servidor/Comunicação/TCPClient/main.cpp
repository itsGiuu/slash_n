#include <iostream>
#include <string>
#include <QCoreApplication>
#include "socket.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Criando um socket da classe "socket"
    socket socketTest;
        //Fixando qual o IP e porta que o módulo wifi está configurado
        QString IP = "192.168.100.10";     //Fixei o IP do módulo wifi nisso
        int port = 8023;                    //Fixei o port que está sendo usado nisso
        socketTest.setIP(IP);
        socketTest.setPort(port);

    //Inicia conexão
    socketTest.doConnect();

    //Criei dois métodos para enviar dados, com array e strings
    //Ambos funcionam, mas strings podem ser mais fáceis de trabalhar
    char *data_array = "Teste array\n";
    string data_string = "Teste string\n";
    socketTest.writeMessage(data_array);
    socketTest.writeMessage(data_string);


    //Percebi um "problema" ao mandar muitos dados para o ESP
    //O seguinte pacote (5025 bytes) é separado em vários pacotes menores
    //A conexão não é fechada, só são mandados separadamente
    //Talvez seja uma funcionalidade do próprio TCP, mas vale lembrar

    for(int i=0;i<1000;i++){
        socketTest.writeMessage("RUN \n");
    }


    //Disconecta a conexão
    //A conexão do servidor é aconselhável deixar sempre aberta
    //A do smartphone não tem muito motivo para deixar sempre ativo
    socketTest.disconnect();
    return a.exec();
}
