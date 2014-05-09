/*
 * iocppm328p.h
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 *
 * C++ implementation of iom328p
 *
 */

#ifndef IOCPPM328P_H_
#define IOCPPM328P_H_


#include <inttypes.h>
#include "interrupt.h"
#include "common.h"

namespace MCU
{
//	using namespace MCUCommon;

	namespace IO
	{
		enum Register8
		{
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
			SMCR=0x33,
			MCUSR=0x34,
			MCUCR=0x35,
			SPMCSR=0x37,
		};
		enum Register16
		{
			EEAR=0x21,
		};
		namespace EEPROM_CR
		{
			enum Bits
			{
				EERE=0,
				EEPE=1,
				EEMPE=2,
				EERIE=3,
				EEPM0=4,
				EEPM1=5,
			};
		}
		namespace TCCR_B
		{
			enum Bits
			{
				CS0=0,
				CS1=1,
				CS2=2,
				WGM2=3,
				FOCB=6,
				FOCA=7,
			};
		}
		namespace TCCR_A
		{
			enum Bits
			{
				WGM0 =0,
				WGM1 =1,
				COMB0=4,
				COMB1=5,
				COMA0=6,
				COMA1=7,
			};
		}
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
		};
	}
}
#define INT0_vect         _VECTOR(1)  /* External Interrupt Request 0 */
#define INT1_vect         _VECTOR(2)  /* External Interrupt Request 1 */
#define PCINT0_vect       _VECTOR(3)  /* Pin Change Interrupt Request 0 */
#define PCINT1_vect       _VECTOR(4)  /* Pin Change Interrupt Request 1 */
#define PCINT2_vect       _VECTOR(5)  /* Pin Change Interrupt Request 2 */
#define WDT_vect          _VECTOR(6)  /* Watchdog Time-out Interrupt */
#define TIMER2_COMPA_vect _VECTOR(7)  /* Timer/Counter2 Compare Match A */
#define TIMER2_COMPB_vect _VECTOR(8)  /* Timer/Counter2 Compare Match B */
#define TIMER2_OVF_vect   _VECTOR(9)  /* Timer/Counter2 Overflow */
#define TIMER1_CAPT_vect  _VECTOR(10)  /* Timer/Counter1 Capture Event */
#define TIMER1_COMPA_vect _VECTOR(11)  /* Timer/Counter1 Compare Match A */
#define TIMER1_COMPB_vect _VECTOR(12)  /* Timer/Counter1 Compare Match B */
#define TIMER1_OVF_vect   _VECTOR(13)  /* Timer/Counter1 Overflow */
#define TIMER0_COMPA_vect _VECTOR(14)  /* Timer/Counter0 Compare Match A */
#define TIMER0_COMPB_vect _VECTOR(15)  /* Timer/Counter0 Compare Match B */
#define TIMER0_OVF_vect   _VECTOR(16)  /* Timer/Counter0 Overflow */
#define SPI_STC_vect      _VECTOR(17)  /* SPI Serial Transfer Complete */
#define USART_RX_vect     _VECTOR(18)  /* USART0, Rx Complete */
#define USART_UDRE_vect   _VECTOR(19)  /* USART0 Data register Empty */
#define USART_TX_vect     _VECTOR(20)  /* USART0, Tx Complete */
#define ADC_vect          _VECTOR(21)  /* ADC Conversion Complete */
#define EE_READY_vect     _VECTOR(22)  /* EEPROM Ready */
#define ANALOG_COMP_vect  _VECTOR(23)  /* Analog Comparator */
#define TWI_vect          _VECTOR(24)  /* 2-wire Serial Interface */
#define SPM_READY_vect    _VECTOR(25)  /* Store Program Memory Read */

#define _VECTORS_SIZE (26 * 4)

#define SPM_PAGESIZE 128
#define RAMEND       0x8FF    /* Last On-Chip SRAM Location */
#define XRAMSIZE     0
#define XRAMEND      RAMEND
#define E2END        0x3FF
#define E2PAGESIZE   4
#define FLASHEND     0x7FFF


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
#define FUSE_CKDIV8 (unsigned char)~_BV(7) /* Divide clock by 8 */
#define LFUSE_DEFAULT (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3 & FUSE_SUT0 & FUSE_CKDIV8)

/* High Fuse Byte */
#define FUSE_BODLEVEL0 (unsigned char)~_BV(0)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL1 (unsigned char)~_BV(1)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL2 (unsigned char)~_BV(2)  /* Brown-out Detector trigger level */
#define FUSE_EESAVE    (unsigned char)~_BV(3)  /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON     (unsigned char)~_BV(4)  /* Watchdog Timer Always On */
#define FUSE_SPIEN     (unsigned char)~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_DWEN      (unsigned char)~_BV(6)  /* debugWIRE Enable */
#define FUSE_RSTDISBL  (unsigned char)~_BV(7)  /* External reset disable */
#define HFUSE_DEFAULT (FUSE_SPIEN)

/* Extended Fuse Byte */
#define FUSE_BOOTRST (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0 (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1 (unsigned char)~_BV(2)
#define EFUSE_DEFAULT (FUSE_BOOTSZ0 & FUSE_BOOTSZ1)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#define SIGNATURE_2 0x0F


#endif /* IOCPPM328P_H_ */
