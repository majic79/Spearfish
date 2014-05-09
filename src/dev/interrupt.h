/*
 * interrupt.h
 *
 *  Created on: 9 May 2014
 *      Author: Chris Marr
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <inttypes.h>

#define _VECTOR(N) __vector_ ## N

#define sei()  __asm__ __volatile__ ("sei" ::)
#define cli()  __asm__ __volatile__ ("cli" ::)
#define reti()  __asm__ __volatile__ ("reti" ::)

#if !defined(__STRINGIFY)
/* Auxiliary macro for ISR_ALIAS(). */
#define __STRINGIFY(x) #x
#endif

#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || (__GNUC__ > 4)
#  define __INTR_ATTRS used, externally_visible
#else /* GCC < 4.1 */
#  define __INTR_ATTRS used
#endif

#define ISR(vector, ...)            \
extern "C" void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)

#define SIGNAL(vector)					\
extern "C" void vector(void) __attribute__ ((signal, __INTR_ATTRS));	\
void vector (void)

#define EMPTY_INTERRUPT(vector)                \
extern "C" void vector(void) __attribute__ ((signal,naked,__INTR_ATTRS));    \
void vector (void) {  __asm__ __volatile__ ("reti" ::); }

#if defined(__AVR_MEGA__) && __AVR_MEGA__
	#define ISR_ALIAS(vector, tgt) extern "C" void vector (void) \
		__attribute__((signal, naked, __INTR_ATTRS)); \
		void vector (void) { asm volatile ("jmp " __STRINGIFY(tgt) ::); }
#else /* !__AVR_MEGA */
	#define ISR_ALIAS(vector, tgt) extern "C" void vector (void) \
		__attribute__((signal, naked, __INTR_ATTRS)); \
		void vector (void) { asm volatile ("rjmp " __STRINGIFY(tgt) ::); }
#endif  /* __AVR_MEGA__ */

#define BADISR_vect __vector_default
#define ISR_BLOCK
#define ISR_NOBLOCK    __attribute__((interrupt))
#define ISR_NAKED      __attribute__((naked))
#define ISR_ALIASOF(v) __attribute__((alias(__STRINGIFY(v))))


#endif /* INTERRUPT_H_ */
