/*
 * Axis.h
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 *
 *  Axis motion class, based on a stepper and an endstop
 */

#ifndef AXIS_H_
#define AXIS_H_

#include "Stepper.h"
#include "Endstop.h"

class CAxis : CStepper, CEndstop {
public:
	CAxis();
	virtual ~CAxis();
};

#endif /* AXIS_H_ */
