/*
 * main.cpp
 *
 *  Created on: 24 Apr 2014
 *      Author: Chris Marr
 *
 *  Main routines to start and run Spearfish RepRap CNC firmware
 *  contains setup() and loop() routines, as well as primary application class
 *
 */

#include <Arduino.h>

#include "Spearfish.h"
#include "Config.h"

// The C++ way to do this is to declare a pointer and then create a new instance in setup()
CSpearfish *SF;

// This will only use the default handler for configuration so default (empty) constructor is fine
CConfig config;

// Standard Arduino setup() function called for initialisation
void setup()
{
	// Create new instance and call the constructor, passing in the configuration class.
	config.RetrieveSettings();
	SF=new CSpearfish(config);
	Serial.begin(config.getBaudRate());
	Serial.println(PSTR("Start"));
}

// Standard Arduino loop() function that repetitively loops through the process
void loop()
{

}



