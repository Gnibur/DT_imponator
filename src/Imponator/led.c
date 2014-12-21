#include "led.h"
#include "timer.h"

#include <avr/interrupt.h> 

volatile Color_t leds[16];
static volatile uint8_t currentLed;

void led_init(void){
	
	cli();
	// setup timers for driving 4 leds, currentled..currentled+3
	TIMER0_init(&TCC0, TC_WGMODE_NORMAL_gc, TC_CLKSEL_DIV1_gc, 0xFFFF);
	TIMER0_init(&TCD0, TC_WGMODE_NORMAL_gc, TC_CLKSEL_DIV1_gc, 0xFFFF);
	TIMER0_init(&TCE0, TC_WGMODE_NORMAL_gc, TC_CLKSEL_DIV1_gc, 0xFFFF);
	TIMER0_init(&TCF0, TC_WGMODE_NORMAL_gc, TC_CLKSEL_DIV1_gc, 0xFFFF);
		
	// setup 3 interrupt for each timer/led. 
	uint8_t CC_config		= (TC0_CCAEN_bm|TC0_CCBEN_bm|TC0_CCCEN_bm);
	uint8_t CC_interrupts	= (TC_CCAINTLVL_HI_gc|TC_CCBINTLVL_HI_gc|TC_CCCINTLVL_HI_gc);
	TIMER0_setupInterrupts(&TCC0,CC_config,TC_OVFINTLVL_HI_gc,CC_interrupts);
	TIMER0_setupInterrupts(&TCD0,CC_config,TC_OVFINTLVL_HI_gc,CC_interrupts);
	TIMER0_setupInterrupts(&TCE0,CC_config,TC_OVFINTLVL_HI_gc,CC_interrupts);
	TIMER0_setupInterrupts(&TCF0,CC_config,TC_OVFINTLVL_HI_gc,CC_interrupts);

	// enable interrupts
	sei();
	
}
/*

ISR(TCC0_OVF_vect)
{
	currentLed += 4;
	if (currentLed == 16)
	{
		currentLed = 0;
		LED_SWITCH_PORT &= ~(1<<LED0_8_SWITCH_PIN);
		LED_SWITCH_PORT |= 
	}
	TCC0->CCA = leds[currentLed].red;
	TCC0->CCB = leds[currentLed].green;
	TCC0->CCB = leds[currentLed].blue;
	ledPort[currentLed] |= redPin[currentLed] | bluePin[currentLed] | greenPin[currentLed];
}
ISR(TCD0_OVF_vect)
{
	TCC0->CCA = leds[currentLed+1].red;
	TCC0->CCB = leds[currentLed+1].green;
	TCC0->CCB = leds[currentLed+1].blue;
	LEDPORT(currentLed) |= (LED(R)|LED(G)|(LED(B)); 
}
ISR(TCE0_OVF_vect)
{
	LEDPORT(currentLed) |= (LED(R)|LED(G)|(LED(B)); 
}
ISR(TCF0_OVF_vect)
{
	LEDPORT(currentLed) |= (LED(R)|LED(G)|(LED(B)); 
}

ISR(TCC0_CCA_vect)
{
	ledPort[currentLed] &= ~redPin[currentLed];
}
ISR(TCC0_CCB_vect)
{
	LEDPORT(currentLed) &= ~LED(G);
}
ISR(TCC0_CCC_vect)
{
	LEDPORT(currentLed) &= ~LED(B);
}

*/