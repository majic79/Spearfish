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

#include <avr/pgmspace.h>
#include "HardwareSerial.h"
#include "Config.h"

class CSpearfish {
public:
	CSpearfish();
	virtual ~CSpearfish();
	void DoSetup();
	int DoLoop();

	void inline StartSerial(){if(m_Cfg && m_Ser)m_Ser->begin(m_Cfg->getBaudRate());}

	CSpearfish & operator=(CConfig &cfg){m_Cfg=&cfg; return *this;};
	CSpearfish & operator=(HardwareSerial &ser){m_Ser=&ser;	return *this;};

private:
	CConfig *m_Cfg;
	HardwareSerial *m_Ser;
};

#endif /* SPEARFISH_H_ */
