/*
 * Spearfish.h
 *
 *  Created on: 24 Apr 2014
 *      Author: Chris Marr
 *
 *      Spearfish application firmware class
 *      Interfaces between serial communication and hardware via G-codes
 *      G-codes are of Marlin flavour (unless I find a limitation with them...)
 */

#ifndef SPEARFISH_H_
#define SPEARFISH_H_

//#include <avr/pgmspace.h>

//#include "HardwareSerial.h"
#include "Config.h"

#include <stdlib.h>

// Derive CSpearfish from an underlying config class (stored in EEPROM)
class CSpearfish : public CConfig
{
public:
	CSpearfish();
	virtual ~CSpearfish();
	void DoSetup();
	int DoLoop();

	//CSpearfish& operator=(HardwareSerial &ser){m_Ser=&ser;	return *this;};

private:
//	HardwareSerial *m_Ser;
	void *m_Ser;
};

#endif /* SPEARFISH_H_ */
