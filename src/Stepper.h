/*
 * Stepper.h
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 *
 *  Simple Pololu A4988 Stepper driver class
 *  Inputs:
 *  /EN, MS1, MS2, MS3, /RST, /SLP, STEP, DIR
 *
 *  Gen7 uses the following signals:
 *  /EN (shared with all steppers for a general motors On/Off signal), DIR, STEP
 */

#ifndef STEPPER_H_
#define STEPPER_H_

class CStepper {
public:
	CStepper();
	virtual ~CStepper();
};

#endif /* STEPPER_H_ */
