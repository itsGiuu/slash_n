/*
 * JsonHandler.cpp
 *
 *  Created on: 05/06/2017
 *      Author: rober
 */

#include "JsonHandler.h"

JsonHandler::JsonHandler(){
	Serial.println("Created Handler");

	arvore.inserirNodo(10,50);
	arvore.inserirNodo(5,49);
	arvore.inserirNodo(4,34);
	arvore.inserirNodo(3,345);
	arvore.inserirNodo(2,345);
	arvore.inserirNodo(1,345);
	arvore.inserirNodo(100,345);
	//arvore.imprimirABB();

}

void JsonHandler::handleData(char* data){
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
			Serial.println("Tipo update multiplos: ");
			for(int i=0;i<size;i++){
				int matr = root["students"][i]["matr"];
				int cred = root["students"][i]["cred"];
				Serial.print(matr);
				Serial.print(" / ");
				Serial.println(cred);
				arvore.inserirNodo(matr,cred);
			}
		}

}


