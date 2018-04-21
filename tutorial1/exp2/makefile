SRCS := main.c add.c subtract.c
OBJECTS := $(SRCS:.c=.o)
LDFLAGS :=
CFLAGS := -Wall -g

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
main.o: add.o subtract.o

.PHONY: clean

clean:
	rm *.o main
