/*
 * Spearfish.cpp
 *
 *  Created on: 24 Apr 2014
 *      Author: Chris
 */

#include "Spearfish.h"

CSpearfish::CSpearfish(CConfig &cfg) :
	mCfg(cfg)
{
	// default constructor
}

CSpearfish::~CSpearfish() {
	// default destructor to handle resource release
	// although we probably don't need any for this class,
	// as it is the be-all and end-all for this firmware
}

void CSpearfish::DoSetup()
{
	//	do setup initialisation
}

int CSpearfish::DoLoop()
{
	//	Check buffer
	//	Do moves
	return 0;
}
