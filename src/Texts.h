/*
 * Texts.h
 *
 *  Created on: 29 Apr 2014
 *      Author: Chris Marr
 *
 *      Creates tables of text strings for storing in flash for use in firmware
 */

#ifndef TEXTS_H_
#define TEXTS_H_

#include <avr/pgmspace.h>

extern const char PROGMEM __alphabet[];

extern const char PROGMEM *__text[];

#define SF_TEXT(a) __text[a]

//	Text ID's for texts we want to pull out of flash
#define TID_FIRMWARE	0
#define TID_READY		1


#endif /* TEXTS_H_ */
