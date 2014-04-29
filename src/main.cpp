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
// But we should try to dynamically allocate memory in an embedded device, so here's our instance class
CSpearfish SF;

// This will only use the default handler for configuration so default (empty) constructor is fine
CConfig config;

// Standard Arduino setup() function called for initialisation
void setup()
{
	// Proper way is to create a new constructor and pass in the Config and Serial instances we're using.
	// we'll fudge it using static instances of the class and refer to them directly

	// Pass Spearfish the config object (it'll retrieve settings when we pass it in)
	SF = config;
	// Pass Spearfish the Serial object
	SF = Serial;

	// Tell Spearfish to begin it's own setup
	SF.DoSetup();
}

// Standard Arduino loop() function that repetitively loops through the process
void loop()
{
	SF.DoLoop();
}



