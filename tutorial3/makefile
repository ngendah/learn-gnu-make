CFLAGS = -fPIC -Wall -Wextra -g
LDFLAGS = -shared
VERSION = 1.0.0

all: libapp

libapp: lib.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o$@.so.$(VERSION) -Wl,-soname,$@.so.1
	ldconfig -n .
	ln -s $@.so.1 $@.so	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm *.o libapp*
