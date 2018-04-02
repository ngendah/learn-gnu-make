APP_NAME = hello_app
CFLAGS = -g -Wall
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
	cp ./$(APP_NAME) %{bindir}

uninstall:
	rm -f %{bindir}/$(APP_NAME)

clean:
	-rm *.o main
