/*
 * Endstop.h
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 *
 *  Endstop class defining Pin configuration of the Endstop and wether it's switched high or low
 */

#ifndef ENDSTOP_H_
#define ENDSTOP_H_

#include <inttypes.h>

class CEndstop {
public:
	CEndstop();
	virtual ~CEndstop();

	void Inverting(bool bInverting);
	bool Inverting();

	//	Return current Endstop state
	bool State();

	void Pin(int nPin){m_nPin = nPin;};

private:
	int m_nPin;
	uint8_t m_Properties;
};

#endif /* ENDSTOP_H_ */
