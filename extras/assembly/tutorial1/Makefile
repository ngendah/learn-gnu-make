march := $(shell arch)
elffmt := "elf32"

ifeq ("$(march)", "x86_64")
elffmt := "elf64"
endif

.PHONY: clean

all: main

main: hello.o
	$(CC) -o $@ $<
	
%.o: %.$(march).S
	nasm -f $(elffmt) -o $@ $<
	
clean:
	rm *.o main