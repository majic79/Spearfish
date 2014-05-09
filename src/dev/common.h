/*
 * common.h
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <inttypes.h>

namespace MCU
{

	static const uint8_t baseAddr=0x20;
	template <typename S, typename RegType>
	inline volatile S *regAddress(RegType reg)
	{
		return reinterpret_cast<volatile S*>(baseAddr+reg);
	}

	template <typename S, typename MemType>
	inline volatile S *memAddress(MemType reg)
	{
		return reinterpret_cast<volatile S*>(reg);
	}

	template < typename S, typename T>
	inline volatile S bitRead(T reg, uint8_t bit)
	{
		S val = *regAddress(reg);
		S mask = ~(1 << bit);
		return ((val & mask) >> bit);
	}

	template <typename S, typename T>
	inline volatile void bitWrite(T reg, uint8_t bit, bool val)
	{
		S rval = *regAddress<S>(reg);
		S mask = ~(1 << bit);
		rval &= mask;
		if(val)
			rval |= (((S)1) << bit);
		*regAddress<S>(reg) = rval;
	}

	template <typename T>
	inline volatile bool bitSet(T reg, uint8_t bit)
	{
		return (*regAddress<uint8_t>(reg) & ((uint8_t)((uint8_t)1 << bit))) ? true : false;
	}

	enum Register8
	{
#if __AVR_ARCH__!=1
		XL=0x1A,
		XH=0x1B,
		YL=0x1C,
		YH=0x1D,
#endif
		ZL=0x1E,
		ZH=0x1F,
		SPL=0x3D,
		SP=0x3D,
		SREG=0x3F,
	};

	enum Bit
	{
		BIT0=0,
		BIT1=1,
		BIT2=2,
		BIT3=3,
		BIT4=4,
		BIT5=5,
		BIT6=6,
		BIT7=7,
	};
	namespace STATUS_REG
	{
		enum Bit
		{
			C=0,
			Z=1,
			N=2,
			V=3,
			S=4,
			H=5,
			T=6,
			I=7
		};
	}
}




#endif /* COMMON_H_ */
