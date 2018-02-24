SRCS = main.c add.c subtract.c
OBJECTS = $(SRCS:.c=.o)
CFLAGS = -g -Wall

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o main
