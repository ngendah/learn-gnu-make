CFLAGS := -fPIC -Wall -Wextra -g
LDFLAGS := -shared
VERSION := 1.0.0

.PHONY: clean

all: libapp

libapp: lib.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o$@.so.$(VERSION) -Wl,-soname,$@.so.1
	ldconfig -n .
	ln -s $@.so.1 $@.so	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm *.o libapp*
