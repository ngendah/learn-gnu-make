CC := avr-gcc
HEX := avr-objcopy
CFLAGS := -Wall -mmcu=atmega16 -std=gnu99 -Os -gdwarf-2
SRCS := $(wildcard *.c)
OBJECTS := $(SRCS:.c=.o)
HEXFLAGS := -j .text -j .data -O ihex


.PHONY: clean

all: main

keypad: main.elf
	$(HEX) $(HEXFLAGS) $^ $@.hex 

main: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@.elf
		
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	rm *.hex *.o *.elf	