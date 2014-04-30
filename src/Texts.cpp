/*
 * Texts.cpp
 *
 *  Created on: 29 Apr 2014
 *      Author: Chris Marr
 */

#include <avr/pgmspace.h>
#include "Texts.h"
#include "Language.h"

const char PROGMEM __alphabet[]={
		'A','B','C','D','E','F',
		'G','H','I','J','K','L','M',
		'N','O','P','Q','R','S',
		'T','U','V','W','X','Y','Z',
		'0','1','2','3','4','5','6','7','8','9',
		'(',')',':',
			};

const char* PROGMEM __text[]={
		LANG_FIRMWARE,			//	Firmware name
		LANG_READY,				//	Ready message
		" (",					//	Date Prefix
		__DATE__,				//	Compilation date
};



