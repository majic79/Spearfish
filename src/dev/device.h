/*
 * device.h
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 */

#ifndef DEVICE_H_
#define DEVICE_H_

#if defined (__AVR_ATmega1284P__)
#  include "iocppm1284p.h"
#elif defined (__AVR_ATmega328P__) || defined (__AVR_ATmega328__)
#  include "iocppm328p.h"
#elif defined (__AVR_ATmega644P__)
#  include "iocppm644p.h"
#endif

#endif /* DEVICE_H_ */
