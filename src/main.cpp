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

// Un-comment this line to show a serial keep alive message every second
#define KEEPALIVE

#ifdef KEEPALIVE
unsigned long kaTimer;
bool bState = false;
#endif

// The C++ way to do this is to declare a pointer and then create a new instance in setup()
// But we should try to dynamically allocate memory in an embedded device, so here's our instance class
CSpearfish SF;

// This will only use the default handler for configuration so default (empty) constructor is fine
CConfig config;

// Standard Arduino setup() function called for initialisation
void setup()
{
	// Proper way is to create a new constructor and pass in the Config and Serial instances we're using.
	// we'll fudge it using static instances of the class and refer to them directly

	// Pass Spearfish the Serial object we'll use for communication with the outside world
	SF = Serial;

	// Tell Spearfish to begin setting up
	SF.DoSetup();
#ifdef KEEPALIVE
	kaTimer = 0;
	pinMode(LED_BUILTIN, OUTPUT);
#endif
}

// Standard Arduino loop() function that repetitively loops through the process
void loop()
{
	SF.DoLoop();
#ifdef KEEPALIVE
	unsigned long time,diff;
	time = millis();
	diff = time - kaTimer;
	if(diff >= 1000)
	{
		if(bState)
		{
			bState = false;
			digitalWrite(LED_BUILTIN,HIGH);
		}
		else
		{
			bState = true;
			digitalWrite(LED_BUILTIN,LOW);
		}

		kaTimer = time;
		Serial.print("Keepalive (");
		Serial.print(diff);
		Serial.println(")");
	}
#endif
}



