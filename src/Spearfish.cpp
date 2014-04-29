/*
 * Spearfish.cpp
 *
 *  Created on: 24 Apr 2014
 *      Author: Chris
 */

#include "Spearfish.h"
#include "Texts.h"

#define SERIAL_OUT(a)	if(m_Ser)m_Ser->print(SF_TEXT(a));
#define SERIAL_OUT_LN(a)	if(m_Ser)m_Ser->println(SF_TEXT(a));

CSpearfish::CSpearfish()
{
	// default constructor
	// We ought to take in the CConfig class instance we're going to use in
	// here, but as we're not dynamically allocating memory (like good boys)
	// we'll pass it in later (see CSpearfish & operator=(const CConfig &) override)
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
	SERIAL_OUT_LN(TID_FIRMWARE);

	//	Any other initialisation

	SERIAL_OUT_LN(TID_READY)
}

int CSpearfish::DoLoop()
{
	//	Check buffer
	//	Do moves
	return 0;
}
