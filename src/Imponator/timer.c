#include "timer.h"

void TIMER0_init(volatile TC0_t *timer,
				TC_WGMODE_t mode,
				TC_CLKSEL_t clkDiv,
				uint16_t period)
{
	timer->CTRLB = mode;
	timer->CTRLA = clkDiv;
	timer->PER = period;
 
}
void TIMER1_init(volatile TC1_t *timer,
				TC_WGMODE_t mode,
				TC_CLKSEL_t clkDiv,
				uint16_t period)
{
	timer->CTRLB = mode;
	timer->CTRLA = clkDiv;
	timer->PER = period;
}

void TIMER0_setupInterrupts(volatile TC0_t *timer,
							uint8_t CC_gc, 
							uint8_t INTCTRLA, 
							uint8_t INTCTRLB)
{
	timer->CTRLB	|= CC_gc;
	timer->INTCTRLA = INTCTRLA;
	timer->INTCTRLB = INTCTRLB;
}



void TIMER1_setupInterrupts(volatile TC1_t *timer,
							uint8_t CC_gc,
							uint8_t INTCTRLA,
							uint8_t INTCTRLB)
{
	timer->CTRLB	|= CC_gc;
	timer->INTCTRLA = INTCTRLA;
	timer->INTCTRLB = INTCTRLB;
}