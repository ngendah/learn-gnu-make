CFLAGS = -fPIC -Wall -Wextra -g
LDFLAGS = -shared
VERSION = 1.0.0

all: libapp

libapp: lib.o
	$(CC) $^ -o$@.so.$(VERSION) -Wl,-soname,$@.so.1 $(CFLAGS) $(LDFLAGS)
	ln -s $@.so.1 $@.so
	ldconfig -n .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o *.so*
