/*
 * JsonHandler.cpp
 *
 *  Created on: 05/06/2017
 *      Author: rober
 */

#include "JsonHandler.h"
#define ENTRADA 0 //GPIO D3
#define SAIDA 4   //GPIP D2

void DispatchInterruptEntrada(){
	catraca.interruptEntrada();
}

void DispatchInterruptSaida(){
	catraca.interruptSaida();
}


JsonHandler::JsonHandler(){
	Serial.println("Created Handler");

	//Server update

	//Teste árvore
	arvore.inserirNodo(10,50);
	arvore.inserirNodo(5,49);
	arvore.inserirNodo(4,34);
	arvore.inserirNodo(3,345);
	arvore.inserirNodo(2,345);
	arvore.inserirNodo(1,345);
	arvore.inserirNodo(100,345);


	//Setup catraca
	attachInterrupt(ENTRADA, DispatchInterruptEntrada,FALLING);
	attachInterrupt(SAIDA, DispatchInterruptSaida,FALLING);
}

void JsonHandler::handleData(char* data,TcpClient& client){
	DynamicJsonBuffer jsonBuffer;
	JsonObject& root = jsonBuffer.parseObject(data);

	if (!root.success()) {
		Serial.println("parseObject() failed");
		return;
	}
	String responseType = root["responseType"];
	Serial.println(responseType);


	if(responseType == "updateSingle"){
		int matr = root["info"][0];
		int cred = root["info"][1];
		Serial.print("Tipo update single: ");
		Serial.print(matr);
		Serial.print(" / ");
		Serial.println(cred);
		arvore.inserirNodo(matr,cred);
	}

	if(responseType == "updateMult"){
		int size = root["size"];
		Serial.println("Tipo: update multiplos: ");
		for(int i=0;i<size;i++){
			int matr = root["students"][i]["matr"];
			int cred = root["students"][i]["cred"];
			Serial.print(matr);
			Serial.print(" / ");
			Serial.println(cred);
			arvore.inserirNodo(matr,cred);
		}
	}

	if(responseType == "getUpdates"){
		Serial.println("Trying to add data to entry list");
		listaEntrada.addEntry(101);
		listaEntrada.addEntry(2);
		listaEntrada.addEntry(3);
		listaEntrada.addEntry(4);
		Serial.println("trying to get response");
		DynamicJsonBuffer jsonBuffer;
		JsonObject& root = jsonBuffer.createObject();

		root["responseType"] = "entryList";
		int size = listaEntrada.size;
		root["size"] = size;
		JsonArray& data = root.createNestedArray("entradas");

		for(int i=0;i<size;i++){
			data.add(listaEntrada.getHead());
		}
		String jsonString;
		root.printTo(jsonString);
		Serial.println(jsonString);
		client.sendString(jsonString,false);
	}

	if(responseType == "setVerification"){
		int verification = root["verification"];
		catraca.setVerification(verification);
	}

	if(responseType == "getVerification"){
		//TODO return catraca.getVerification();
	}
}




