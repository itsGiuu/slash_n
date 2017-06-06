/*
 * JsonHandler.h
 *
 *  Created on: 05/06/2017
 *      Author: rober
 */

#ifndef INCLUDE_JSONHANDLER_H_
#define INCLUDE_JSONHANDLER_H_

#include <user_config.h>
#include <SmingCore/SmingCore.h>
#include <string>
#include "Services/ArduinoJson/include/ArduinoJson.h"
#include "ABB.cpp"

class JsonHandler{
public:
	JsonHandler();
	void handleData(char* data);

private:
	ABB arvore;
	DynamicJsonBuffer jsonBuffer;
};


#endif /* INCLUDE_JSONHANDLER_H_ */
