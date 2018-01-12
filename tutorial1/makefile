all: main

main: main.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean

clean:
	rm *.o main
