/*
 * Endstop.cpp
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 */

#include "Endstop.h"

// Short bit masks for Endstop properties
#define ES_PROPMASK_INV 0xFFFE
#define ES_INV_SHIFT 0

CEndstop::CEndstop() :
	m_nPin(0),
	m_Properties(0)
{
	// constructor stub

}

CEndstop::~CEndstop() {
	// Auto-generated destructor stub
}


void CEndstop::Inverting(bool bInverting)
{
	// Set "Inverting" flag in properties
	uint8_t tmp;
	tmp = bInverting << ES_INV_SHIFT;
	m_Properties &= (ES_PROPMASK_INV | tmp);
}

bool CEndstop::Inverting()
{
	bool bRet;
	bRet = (m_Properties & ~ES_PROPMASK_INV) >> ES_INV_SHIFT;
	return bRet;
}

bool CEndstop::State()
{
	//	Return the current endstop state (based on pin)
	return false;
}
