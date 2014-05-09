/*
 * iocppm1284p.h
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 *
 * C++ implementation of iom1284p
 *
 */

#ifndef IOCPPM1284P_H_
#define IOCPPM1284P_H_


#include <inttypes.h>

#include "common.h"

namespace MCU
{

	namespace IO
	{
		uint8_t* regAddress(Register8);
		enum Register8
		{
			PIN_A=0x00,
			DDR_A=0x01,
			PORT_A=0x02,
			PIN_B=0x03,
			DDR_B=0x04,
			PORT_B=0x05,
			PIN_C=0x06,
			DDR_C=0x07,
			PORT_C=0x08,
			PIN_D=0x09,
			DDR_D=0x0A,
			PORT_D=0x0B,
			TIFR0=0x15,
			TIFR1=0x16,
			TIFR2=0x17,
			TIFR3=0x18,
			PCIFR=0x1B,
			EIFR=0x1C,
			EIMSK=0x1D,
			GPIOR0=0x1E,
			EECR=0x1F,
			EEDR=0x20,
			EEARL=0x21,
			EEARH=0x22,
			GTCCR=0x23,
			TCCR0A=0x24,
			TCCR0B=0x25,
			TCNT0=0x26,
			OCR0A=0x27,
			OCR0B=0x28,
			GPIOR1=0x2A,
			GPIOR2=0x2B,
			SPCR=0x2C,
			SPSR=0x2D,
			SPDR=0x2E,
			ACSR=0x30,
			OCDR=0x31,
			SMCR=0x33,
			MCUSR=0x34,
			MCUCR=0x35,
			SPMCSR=0x37,
			RAMPZ=0x3B,
		};
		enum Register16
		{
			EEAR=0x21,
		};
	}

	namespace MEM
	{
		enum Register8
		{
			WDTSR=0x60,
			CLKPR=0x61,
			PRR0=0x64,
			PRR1=0x65,
			OSCCAL=0x66,
			PCICR=0x68,
			EICRA=0x69,
			PCMSK0=0x6B,
			PCMSK1=0x6C,
			PCMSK2=0x6D,
			TIMSK0=0x6E,
			TIMSK1=0x6F,
			TIMSK2=0x70,
			TIMSK3=0x71,
			PCMSK3=0x73,
			ADCL=0x78,
			ADCH=0x79,
			ADCSRA=0x7A,
			ADCSRB=0x7B,
			ADMUX=0x7C,
			DIDR0=0x7E,
			DIDR1=0x7F,
			TCCR1A=0x80,
			TCCR1B=0x81,
			TCCR1C=0x82,
			TCNT1L=0x84,
			TCNT1H=0x85,
			ICR1L=0x86,
			ICR1H=0x87,
			OCR1AL=0x88,
			OCR1AH=0x89,
			OCR1BL=0x8A,
			OCR1BH=0x8B,
			TCCR3A=0x90,
			TCCR3B=0x91,
			TCCR3C=0x92,
			TCNT3L=0x94,
			TCNT3H=0x95,
			ICR3L=0x96,
			ICR3H=0x97,
			OCR3AL=0x98,
			OCR3AH=0x99,
			OCR3BL=0x9A,
			OCR3BH=0x9B,
			TCCR2A=0xB0,
			TCCR2B=0xB1,
			TCNT2=0xB2,
			OCR2A=0xB3,
			OCR2B=0xB4,
			ASSR=0xB6,
			TWBR=0xB8,
			TWSR=0xB9,
			TWAR=0xBA,
			TWDR=0xBB,
			TWCR=0XBC,
			TWAMR=0xBD,
			UCSR0A=0xC0,
			UCSR0B=0xC1,
			UCSR0C=0xC2,
			UBRR0L=0xC4,
			UBRR0H=0xC5,
			UDR0=0xC6,
			UCSR1A=0xC8,
			UCSR1B=0xC9,
			UCSR1C=0xCA,
			UBRR1L=0xCC,
			UBRR1H=0xCD,
			UDR1=0xCE,
		};
		enum Register16
		{
			ADC=0x78,
			TCNT1=0x84,
			ICR1=0x86,
			OCR1A=0x88,
			OCR1B=0x8A,
			TCNT3=0x94,
			ICR3=0x96,
			OCR3A=0x98,
			OCR3B=0x9A,
			UBRR0=0xC4,
			UBRR1=0xCC,
		};
	}
}
#define INT0_vect         _VECTOR(1)  /* External Interrupt Request 0 */
#define INT1_vect         _VECTOR(2)  /* External Interrupt Request 1 */
#define INT2_vect         _VECTOR(3)  /* External Interrupt Request 2 */
#define PCINT0_vect       _VECTOR(4)  /* Pin Change Interrupt Request 0 */
#define PCINT1_vect       _VECTOR(5)  /* Pin Change Interrupt Request 1 */
#define PCINT2_vect       _VECTOR(6)  /* Pin Change Interrupt Request 2 */
#define PCINT3_vect       _VECTOR(7)  /* Pin Change Interrupt Request 3 */
#define WDT_vect          _VECTOR(8)  /* Watchdog Time-out Interrupt */
#define TIMER2_COMPA_vect _VECTOR(9)  /* Timer/Counter2 Compare Match A */
#define TIMER2_COMPB_vect _VECTOR(10)  /* Timer/Counter2 Compare Match B */
#define TIMER2_OVF_vect   _VECTOR(11)  /* Timer/Counter2 Overflow */
#define TIMER1_CAPT_vect  _VECTOR(12)  /* Timer/Counter1 Capture Event */
#define TIMER1_COMPA_vect _VECTOR(13)  /* Timer/Counter1 Compare Match A */
#define TIMER1_COMPB_vect _VECTOR(14)  /* Timer/Counter1 Compare Match B */
#define TIMER1_OVF_vect   _VECTOR(15)  /* Timer/Counter1 Overflow */
#define TIMER0_COMPA_vect _VECTOR(16)  /* Timer/Counter0 Compare Match A */
#define TIMER0_COMPB_vect _VECTOR(17)  /* Timer/Counter0 Compare Match B */
#define TIMER0_OVF_vect   _VECTOR(18)  /* Timer/Counter0 Overflow */
#define SPI_STC_vect      _VECTOR(19)  /* SPI Serial Transfer Complete */
#define USART0_RX_vect    _VECTOR(20)  /* USART0, Rx Complete */
#define USART0_UDRE_vect  _VECTOR(21)  /* USART0 Data register Empty */
#define USART0_TX_vect    _VECTOR(22)  /* USART0, Tx Complete */
#define ANALOG_COMP_vect  _VECTOR(23)  /* Analog Comparator */
#define ADC_vect          _VECTOR(24)  /* ADC Conversion Complete */
#define EE_READY_vect     _VECTOR(25)  /* EEPROM Ready */
#define TWI_vect          _VECTOR(26)  /* 2-wire Serial Interface */
#define SPM_READY_vect    _VECTOR(27)  /* Store Program Memory Read */
#define USART1_RX_vect    _VECTOR(28)  /* USART1 RX complete */
#define USART1_UDRE_vect  _VECTOR(29)  /* USART1 Data Register Empty */
#define USART1_TX_vect    _VECTOR(30)  /* USART1 TX complete */
#define TIMER3_CAPT_vect  _VECTOR(31)  /* Timer/Counter3 Capture Event */
#define TIMER3_COMPA_vect _VECTOR(32)  /* Timer/Counter3 Compare Match A */
#define TIMER3_COMPB_vect _VECTOR(33)  /* Timer/Counter3 Compare Match B */
#define TIMER3_OVF_vect   _VECTOR(34)  /* Timer/Counter3 Overflow */

#define _VECTORS_SIZE (35 * 4)

#define SPM_PAGESIZE 256
#define RAMEND       0x40FF    /* Last On-Chip SRAM Location */
#define XRAMSIZE     0
#define XRAMEND      RAMEND
#define E2END        0xFFF
#define E2PAGESIZE   8
#define FLASHEND     0x1FFFF


/* Fuses */
#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_CKSEL0 (unsigned char)~_BV(0)  /* Select Clock Source */
#define FUSE_CKSEL1 (unsigned char)~_BV(1)  /* Select Clock Source */
#define FUSE_CKSEL2 (unsigned char)~_BV(2)  /* Select Clock Source */
#define FUSE_CKSEL3 (unsigned char)~_BV(3)  /* Select Clock Source */
#define FUSE_SUT0   (unsigned char)~_BV(4)  /* Select start-up time */
#define FUSE_SUT1   (unsigned char)~_BV(5)  /* Select start-up time */
#define FUSE_CKOUT  (unsigned char)~_BV(6)  /* Clock output */
#define FUSE_CKDIV8 (unsigned char)~_BV(7)  /* Divide clock by 8 */
#define LFUSE_DEFAULT (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3 & FUSE_SUT0 & FUSE_SUT1 & FUSE_CKDIV8)

/* High Fuse Byte */
#define FUSE_BOOTRST (unsigned char)~_BV(0)  /* Select Reset Vector */
#define FUSE_BOOTSZ0 (unsigned char)~_BV(1)  /* Select Boot Size */
#define FUSE_BOOTSZ1 (unsigned char)~_BV(2)  /* Select Boot Size */
#define FUSE_EESAVE  (unsigned char)~_BV(3)  /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON   (unsigned char)~_BV(4)  /* Watchdog timer always on */
#define FUSE_SPIEN   (unsigned char)~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_JTAGEN  (unsigned char)~_BV(6)  /* Enable JTAG */
#define FUSE_OCDEN   (unsigned char)~_BV(7)  /* Enable OCD */
#define HFUSE_DEFAULT (FUSE_BOOTSZ0 & FUSE_SPIEN & FUSE_JTAGEN)

/* Extended Fuse Byte */
#define FUSE_BODLEVEL0 (unsigned char)~_BV(0)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL1 (unsigned char)~_BV(1)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL2 (unsigned char)~_BV(2)  /* Brown-out Detector trigger level */
#define EFUSE_DEFAULT (0xFF)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x97
#define SIGNATURE_2 0x05


#endif /* IOCPPM1284P_H_ */
