/*
 * CatracaEntrada.cpp
 *
 *  Created on: 09/06/2017
 *      Author: rober
 */

#include "Catraca.h"

Catraca::Catraca() {
	ocupacaoRU = 0;
	lastEntradaTime = millis();
	lastSaidaTime = millis();
}

Catraca::~Catraca() {
	// TODO Auto-generated destructor stub
}

int Catraca::getOcupacao(){
	return ocupacaoRU;
}

void Catraca::interruptEntrada(){
	unsigned int currentTime = millis();
	if(lastEntradaTime-currentTime > 1000){
		ocupacaoRU += 1;
		lastEntradaTime = currentTime;
		Serial.println("Entrada!");
	}
}

void Catraca::interruptSaida(){
	unsigned int currentTime = millis();
	if(lastSaidaTime - currentTime > 1000){
		ocupacaoRU -= 1;
		if(ocupacaoRU <0 ){
			ocupacaoRU = 0;
		}
		Serial.println("Saída!");
	}
}

void Catraca::setVerification(int verif){
	//TODO
}
