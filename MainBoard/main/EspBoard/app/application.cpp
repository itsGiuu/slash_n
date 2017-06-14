#include <user_config.h>
#include <SmingCore/SmingCore.h>
#include <SmingCore/Debug.h>

#include "Handler/JsonHandler.cpp"

//#include <SmingCore/Debug.h>

#ifndef WIFI_SSID
	#define WIFI_SSID "admin" // Put you SSID and Password here
	#define WIFI_PWD ""
#endif

IPAddress serverIP;
uint16_t serverPort;
JsonHandler* wifiHandler;


void tcpServerClientConnected (TcpClient* client)
{
	Serial.print("Application ClientConnected (onClientCallback)\n ");
}

bool tcpServerClientReceive(TcpClient& client, char *data, int size)
{
	Serial.print("Application ClientReceive (DataCallback) (IP, port) :");
	Serial.print(client.getRemoteIp().toString()); Serial.print("  ");
	Serial.print(client.getRemotePort()); Serial.print("\n");
	Serial.print(" data :");
	Serial.print(data); Serial.print("\n");

	wifiHandler->handleData(data, client);




	return true;


}



void tcpServerClientComplete(TcpClient& client, bool succesfull)
{
	Serial.print("Application ClientComplete (CompleteCallback)\n\n\n");
}


TcpServer tcpServer(tcpServerClientConnected, tcpServerClientReceive, tcpServerClientComplete);

void startServers()
{
	tcpServer.listen(8025);
	Serial.println("\r\n=== TCP SERVER Port 8025 STARTED ===");
	Serial.println(WifiStation.getIP());
	Serial.println("==============================\r\n");
}



void connectOk()
{
	Serial.print("CONNECTED \n");
	startServers();
}

void connectFail()
{
	Serial.print("Connecting... \n");
	WifiStation.waitConnection(connectOk, 10, connectFail);
}



void init()
{
	delayMilliseconds(3000);
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.commandProcessing(false);


	Serial.systemDebugOutput(true);
	system_set_os_print(0);
	Debug.setDebug(Serial);
	Debug.initCommand();
	Debug.start();

	WifiStation.enable(true);
	WifiStation.config(WIFI_SSID, WIFI_PWD);
	WifiAccessPoint.enable(false);
	//WifiStation.setIP(IPAddress(192,168,100,10));
	WifiStation.waitConnection(connectOk, 30, connectFail);


	wifiHandler = new JsonHandler;

}



