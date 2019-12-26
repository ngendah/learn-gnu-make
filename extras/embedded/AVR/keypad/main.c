#define F_CPU 8000000UL  // 8 MHz

#include <stdio.h>
#include "keypad.h"

void on_keypress(unsigned char key){
}


void main () {
	keypad_init();
	keypad_read(&on_keypress);
}


