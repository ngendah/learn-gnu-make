SRCS = $(shell ls *.c)
OBJECTS = $(SRCS:.c=.o)
CFLAGS = -g

.PHONY: clean

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o main
