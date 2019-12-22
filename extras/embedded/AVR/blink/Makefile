CC := avr-gcc
HEX := avr-objcopy
CFLAGS := -mmcu=atmega8
HEXFLAGS := -j .text -j .data -O ihex

.PHONY: clean

all: main

main: main.o
	$(HEX) $(HEXLFAGS) $^ $@.hex 
	
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	rm *.hex *.o main
