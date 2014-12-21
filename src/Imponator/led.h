/*
Led drawer. 16-bit color coding.
Takes care of led multiplexing.
*/

#ifndef _LED_H_
#define _LED_H_
 
#include <stdint.h>

typedef struct {
	uint16_t red;
	uint16_t green;
	uint16_t blue;
} Color_t;

void led_init(void);

extern volatile Color_t leds[16];

inline void led_set(uint8_t led, Color_t c)
{
	leds[led] = c;
}

#endif 