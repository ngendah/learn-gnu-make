bindir?=/usr/bin
TARGET=$(destdir)$(bindir)
APP_NAME = hello_app
CFLAGS = -Wall
LIB_APP_PATH = ../lib
INCLUDES = -I $(LIB_APP_PATH)
LDFLAGS = -L $(LIB_APP_PATH) -lapp -Wl,--enable-new-dtags

.PHONY: all clean install uninstall

all: $(APP_NAME)

$(APP_NAME): main.o
	$(CC) -o$@ $^ $(CLFAGS) $(LDFLAGS) -t

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
install:
	install -m 0755 -d ${TARGET}
	install -m 0755 ${APP_NAME} ${TARGET}/

uninstall:
	rm -f ${TARGET}/$(APP_NAME)

clean:
	-rm *.o hello_app
