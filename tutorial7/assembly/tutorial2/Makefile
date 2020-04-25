CSRCS := $(wildcard *.c)
ASRCS := $(wildcard *.S)
COBJECTS := $(CSRCS:.c=.o)
SOBJECTS := $(ASRCS:.S=.o)
CFLAGS := -m32
SFLAGS := -felf32
ASM := nasm

.PHONY: clean

all: main

main: $(COBJECTS) $(SOBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(COBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
$(SOBJECTS): %.o: %.S
	$(ASM) $(SFLAGS) -o $@ $<

clean:
	rm *.o main
