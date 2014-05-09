/*
 * pinIO.h
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 */

#ifndef PINIO_H_
#define PINIO_H_

#include <inttypes.h>

#include "dev/device.h"

namespace Pins
{
	using namespace MCU::IO;
//	void pinMode(uint8_t pin, uint8_t mode)
//	{
//		uint8_t bit = digitalPinToBitMask(pin);
//		uint8_t port = digitalPinToPort(pin);
//		volatile uint8_t *reg, *out;
//
//		if (port == NOT_A_PIN) return;
//
//		// JWS: can I let the optimizer do this?
//		reg = portModeRegister(port);
//		out = portOutputRegister(port);
//
//		if (mode == INPUT) {
//			uint8_t oldSREG = SREG;
//	                cli();
//			*reg &= ~bit;
//			*out &= ~bit;
//			SREG = oldSREG;
//		} else if (mode == INPUT_PULLUP) {
//			uint8_t oldSREG = SREG;
//	                cli();
//			*reg &= ~bit;
//			*out |= bit;
//			SREG = oldSREG;
//		} else {
//			uint8_t oldSREG = SREG;
//	                cli();
//			*reg |= bit;
//			SREG = oldSREG;
//		}
//	}

}


#endif /* PINIO_H_ */
