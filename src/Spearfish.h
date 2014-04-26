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

#include "Config.h"

class CSpearfish {
public:
	CSpearfish(CConfig &cfg);
	virtual ~CSpearfish();
	void DoSetup();
	int DoLoop();
private:
	CConfig &mCfg;
};

#endif /* SPEARFISH_H_ */
