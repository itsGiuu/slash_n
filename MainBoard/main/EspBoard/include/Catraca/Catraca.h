/*
 * CatracaEntrada.h
 *
 *  Created on: 09/06/2017
 *      Author: rober
 */

#ifndef INCLUDE_CATRACA_CATRACA_H_
#define INCLUDE_CATRACA_CATRACA_H_

class Catraca {
public:
	Catraca();
	virtual ~Catraca();
	int getOcupacao();
	void setVerification(int verif);
	void interruptEntrada();
	void interruptSaida();
private:
	int ocupacaoRU;
	unsigned int lastEntradaTime;
	unsigned int lastSaidaTime;


};

#endif /* INCLUDE_CATRACA_CATRACA_H_ */
