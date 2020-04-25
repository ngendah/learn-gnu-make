SRCS := $(wildcard *.c)
OBJECTS := $(SRCS:.c=.o)
LDFLAGS :=
CFLAGS = -g

.PHONY: clean

all: main

main: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o main
