/*
 * Spearfish.cpp
 *
 *  Created on: 24 Apr 2014
 *      Author: Chris
 */

#include <avr/pgmspace.h>

#include "Spearfish.h"
#include "Texts.h"

#define SERIAL_OUT(a)			m_Ser->print(a);
#define SERIAL_OUT_LN(a)		m_Ser->println(a);
#define SERIAL_OUT_SF(a)		m_Ser->print(SF_TEXT(a));
#define SERIAL_OUT_SF_LN(a)		m_Ser->println(SF_TEXT(a));

CSpearfish::CSpearfish() :
	m_Ser(NULL)
{
	// default constructor
}

CSpearfish::~CSpearfish()
{
	// default destructor to handle resource release (never actually used!)
}

void CSpearfish::DoSetup()
{
	// If we don't have m_Cfg or m_Ser, then we're doomed from the start...
	// Read configuration settings
	ReadWriteSettings(EEPROM_READ);
	//	Setup the serial line
//	m_Ser->begin(getBaudRate());

	//	Tell whoever's listening who we are
//	SERIAL_OUT_SF(TID_FIRMWARE);SERIAL_OUT_SF(TID_PREFIX);SERIAL_OUT_SF(TID_DATE);SERIAL_OUT_LN(')');
	//	Any other initialisation

//	SERIAL_OUT_SF_LN(TID_READY)
}

int CSpearfish::DoLoop()
{
	//	Check buffer
	//	Do moves
	return 0;
}
