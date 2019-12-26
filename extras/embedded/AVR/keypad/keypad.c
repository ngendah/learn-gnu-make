#include <util/delay.h>

/*
 * Keypad attached to PORTA
 *
 * PINs 0..3 for input, PINs 4..7 for output
 *
*/

void keypad_init(void) {
	DDRA = 0xf0;
	_delay_ms(1);
}

void keypad_read(void (*on_keypress)(unsigned char)) {
	static unsigned char read_cycles[] = {0x70, 0xb0, 0xd0, 0xe0};
	static unsigned char key;
	static unsigned char *p_rc;
	key = 0x0f;
	p_rc = read_cycles;
	while (1) {
		PORTA = *p_rc;
		_delay_ms(1);
		key = (*p_rc | (PINA & 0x0f));
		if ((key & 0x0f) != 0x0f) {
			(*on_keypress)(key);
			_delay_ms(5);
		}
		p_rc++;
		if (*p_rc == 0) {
			p_rc = read_cycles;
			continue;
		}
	}
}
