CFLAGS = -fPIC -Wall -Wextra -g
LDFLAGS = -shared

all: libapp

libapp: lib.o
	$(CC) -o"$@.so" $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o *.so.*
