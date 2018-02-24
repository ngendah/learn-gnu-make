OBJECTS = main.o add.o subtract.o
CFLAGS = -g

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o: add.o subtract.o

.PHONY: clean

clean:
	rm *.o main
