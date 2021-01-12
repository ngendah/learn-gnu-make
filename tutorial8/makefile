include makefile.config

SRCS = $(wildcard *.c)
OBJECTS = $(SRCS:.c=.o)

.PHONY: clean

all: main

main: $(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		-@rm *.o main
