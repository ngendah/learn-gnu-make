CFLAGS = -fPIC -Wall -Wextra -g
LDFLAGS = -shared
VERSION = 1.0.0
LIB_NAME = libapp

.PHONY: all clean install uninstall

all: $(LIB_NAME)

$(LIB_NAME): lib.o
	$(CC) $^ -o$@.so.$(VERSION) -Wl,-soname,$@.so.1 $(CFLAGS) $(LDFLAGS)
	ldconfig -n .
	ln -s $@.so.1 $@.so

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
install:
	cp ./$(LIB_NAME).so* %{libdir}
	
uninstall:
	rm -f %{libdir}/$(LIB_NAME).so*

clean:
	-rm *.o *.so*
