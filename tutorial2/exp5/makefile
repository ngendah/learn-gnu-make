SRCS := $(wildcard *.c)
OBJECTS := $(SRCS:.c=.o)
CFLAGS = -g

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o main
