#include <user_config.h>
#include <SmingCore/SmingCore.h>
#include <SmingCore/Network/TelnetServer.h>
#include "Services/CommandProcessing/CommandProcessingIncludes.h"
//#include <SmingCore/Debug.h>

#ifndef WIFI_SSID
	#define WIFI_SSID "admin" // Put you SSID and Password here
	#define WIFI_PWD ""
#endif

IPAddress serverIP;
uint16_t serverPort;
TcpClient* global_client  = new TcpClient(false);

void handleServerMessage(){
	//global_client.sendString( "Teste global client 1",false);
	global_client->sendString("Response to server 2 \r\n", false);
}


void tcpServerClientConnected (TcpClient* client)
{
	Serial.print("Application ClientConnected (onClientCallback)\n ");
}

bool tcpServerClientReceive (TcpClient& client, char *data, int size)
{
	Serial.print("Application ClientReceive (DataCallback) (IP, port) :");
	Serial.print(client.getRemoteIp().toString()); Serial.print("  ");
	Serial.print(client.getRemotePort()); Serial.print("\n");
	Serial.print(" data :");
	Serial.print(data); Serial.print("\n");

	if (strcmp(data,"server") == 0)	{
		serverIP = client.getRemoteIp();
		serverPort = client.getRemotePort();
		global_client = &client;
		Serial.print("---Received data from server\n"); Serial.print("---Responding.....\n");
		client.sendString("Response to server \r\n", false);
		handleServerMessage();
	}
	else{
		client.sendString("Response to client \r\n", false);
		//client.writeString("Write from esp \r\n",0 );
	}
	return true;
}



void tcpServerClientComplete(TcpClient& client, bool succesfull)
{
	Serial.print("Application ClientComplete (CompleteCallback)\n\n\n");
}


TcpServer tcpServer(tcpServerClientConnected, tcpServerClientReceive, tcpServerClientComplete);

void startServers()
{
	tcpServer.listen(8023);

	Serial.println("\r\n=== TCP SERVER Port 8023 STARTED ===");
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
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	Serial.systemDebugOutput(false); //
	system_set_os_print(0);
	//Serial.commandProcessing(true);
	WifiStation.enable(true);
	WifiStation.config(WIFI_SSID, WIFI_PWD);
	WifiAccessPoint.enable(false);
	//WifiStation.setIP(IPAddress(192,168,100,10));
	WifiStation.waitConnection(connectOk, 30, connectFail);
	/*Debug.setDebug(Serial);
	Debug.initCommand();
	Debug.start();
	Debug.printf("This is the debug output\r\n");
	 */

}
