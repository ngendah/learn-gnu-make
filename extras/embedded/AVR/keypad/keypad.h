#ifndef _AVR_KEYPAD_H_
#define _AVR_KEYPAD_H_

/*
 * 4 x 4 keypad
 */

#define KEYPAD_PORT = A

void keypad_init(void);
void keypad_read(void (*on_keypress)(unsigned char));

#endif
