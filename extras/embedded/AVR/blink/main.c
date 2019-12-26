/* ledblink.c, an LED blinking program */
#define F_CPU 1000000ul

extern DDRC;
extern PORTC;
extern PC2;

#include <avr/io.h>
#include <util/delay.h>

void sleep(uint8_t millisec) {
	while(millisec)	{
		_delay_ms(1);/* 1 ms delay */
		millisec--;
	}
}

void main() {
	//Data Direction Register For PORT C
	DDRC |= 1 << PC2; /* PC2 will now be the output pin */
	while (1){
		PORTC &= ~ (1 << PC2);/* PC2 LOW */
		sleep(100);/* 100 ms delay */

		PORTC |= (1 << PC2); /* PC2 HIGH */
		sleep(100);/* 100 ms delay */
	}
}
