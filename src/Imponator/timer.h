/*
Timer library for easier timer configuration
Check datasheet for more details.
*/

#ifndef _TIMER_H_
#define _TIMER_H_

#include <avr/io.h>
#include <stdint.h>

void TIMER0_init(volatile TC0_t *timer, 
				TC_WGMODE_t mode,
				TC_CLKSEL_t clkDiv,
				uint16_t period);
				
void TIMER1_init(volatile TC1_t *timer,
				TC_WGMODE_t mode,
				TC_CLKSEL_t clkDiv,
				uint16_t period);
				
void TIMER0_setupInterrupts(volatile TC0_t *timer,
							uint8_t CC_gc,
							uint8_t INTCTRLA,
							uint8_t INTCTRLB);

				
void TIMER1_setupInterrupts(volatile TC1_t *timer,
							uint8_t CC_gc,
							uint8_t INTCTRLA,
							uint8_t INTCTRLB);

#endif 