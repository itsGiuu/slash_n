#include <user_config.h>
#include <SmingCore/SmingCore.h>
#include <SmingCore/Network/TelnetServer.h>
#include "Services/CommandProcessing/CommandProcessingIncludes.h"
#include <SmingCore/Debug.h>

// If you want, you can define WiFi settings globally in Eclipse Environment Variables
#ifndef WIFI_SSID
	#define WIFI_SSID "admin" // Put you SSID and Password here
	#define WIFI_PWD ""
#endif




void tcpServerClientConnected (TcpClient* client)
{
	Serial.print("Application ClientConnected (onClientCallback)\n ");
}

bool tcpServerClientReceive (TcpClient& client, char *data, int size)
{
	Serial.print("Application ClientReceive DataCallback (IP, port, size) :");
	Serial.print(client.getRemoteIp().toString()); Serial.print("  ");
	Serial.print(client.getRemotePort()); Serial.print("\n");
	Serial.print(" Data :");
	Serial.print(data); Serial.print("\n");
	client.sendString("String from esp \r\n", false);
	client.writeString("Write from esp \r\n",0 );
	if (strcmp(data,"close") == 0)
	{
		Serial.print("Received \"close\" command");
		client.close();
	};
	return true;
}



void tcpServerClientComplete(TcpClient& client, bool succesfull)
{
	Serial.print("Application ClientComplete CompleteCallback :");
	Serial.print(client.getRemoteIp().toString());
}

TcpServer tcpServer(tcpServerClientConnected, tcpServerClientReceive, tcpServerClientComplete);


void startServers()
{
	tcpServer.listen(8023);

	Serial.println("\r\n=== TCP SERVER Port 8023 STARTED ===");
	Serial.println(WifiStation.getIP());
	Serial.println("==============================\r\n");



}

void writeClient(){
	TcpClient global_client(false);
	global_client.connect(IPAddress(127,0,0,1),7009);
	String data = "Teste global client";
	global_client.sendString(data);
	global_client.close();

}

// Will be called when WiFi station was connected to AP
void connectOk()
{
	Serial.print("CONNECTED \n");
	startServers();
	writeClient();
}

void connectFail()
{
	Serial.print("Connecting... \n");
	WifiStation.waitConnection(connectOk, 10, connectFail);
}

void init()
{
	Serial.begin(SERIAL_BAUD_RATE); // 115200 by default
	//Serial.systemDebugOutput(true); // Enable debug output to serial
	//Serial.commandProcessing(true);
	WifiStation.enable(true);
	WifiStation.config(WIFI_SSID, WIFI_PWD);
	WifiAccessPoint.enable(false);

	// Run our method when station was connected to AP
	WifiStation.waitConnection(connectOk, 30, connectFail);
	/*Debug.setDebug(Serial);
	Debug.initCommand();
	Debug.start();
	Debug.printf("This is the debug output\r\n");
	 */

}
