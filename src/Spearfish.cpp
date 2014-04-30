/*
 * Spearfish.cpp
 *
 *  Created on: 24 Apr 2014
 *      Author: Chris
 */

#include <avr/pgmspace.h>

#include "Spearfish.h"
#include "Texts.h"

#define SERIAL_OUT(a)	if(m_Ser)m_Ser->print(a);
#define SERIAL_OUT_LN(a)	if(m_Ser)m_Ser->println(a);
#define SERIAL_OUT_SF(a)	if(m_Ser)m_Ser->print(SF_TEXT(a));
#define SERIAL_OUT_SF_LN(a)	if(m_Ser)m_Ser->println(SF_TEXT(a));

CSpearfish::CSpearfish()
{
	// default constructor
	// We ought to take in the CConfig class instance we're going to use in
	// here, but as we're not dynamically allocating memory due to this
	// embedded design we'll pass it in later
	// (see "CSpearfish & operator=" overrides)
	m_Cfg=NULL;
	m_Ser=NULL;
}

CSpearfish::~CSpearfish() {
	// default destructor to handle resource release
	// although we probably don't need any for this class,
	// as it is the be-all and end-all for this firmware
}

void CSpearfish::DoSetup()
{
	//	do setup initialisation
	StartSerial();
	SERIAL_OUT_SF(TID_FIRMWARE);SERIAL_OUT_SF(TID_PREFIX);SERIAL_OUT_SF(TID_DATE);SERIAL_OUT_LN(')');
	//	Any other initialisation

	SERIAL_OUT_SF_LN(TID_READY)
}

int CSpearfish::DoLoop()
{
	//	Check buffer
	//	Do moves
	return 0;
}
