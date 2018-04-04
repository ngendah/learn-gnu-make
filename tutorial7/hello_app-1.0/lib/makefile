libdir?=/usr/lib64
TARGET=$(destdir)$(libdir)
CFLAGS = -fPIC -Wall -Wextra
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
	install -m 0755 -d ${TARGET}
	install -m 0755 $(LIB_NAME).so* ${TARGET}/
	
uninstall:
	rm -f ${TARGET}/$(LIB_NAME).so*

clean:
	-rm *.o *.so*
