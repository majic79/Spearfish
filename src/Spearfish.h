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

#ifdef __GNUC__
	#ifndef GCC_VERSION
		#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
	#endif
	#if GCC_VERSION < 40602 // Test for GCC < 4.6.2
		#ifdef PROGMEM
			#undef PROGMEM
			#define PROGMEM __attribute__((section(".progmem.data"))) // Workaround for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=34734#c4
			#ifdef PSTR
				#undef PSTR
				#define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];})) // Copied from pgmspace.h in avr-libc source
			#endif
		#endif
	#endif
#endif

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
