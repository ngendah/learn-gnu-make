OBJECTS := main.o

all: main

main: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o main
