CFLAGS := -g -Wall
LIB_APP_PATH := ../lib
INCLUDES := -I $(LIB_APP_PATH)
LDFLAGS := -L $(LIB_APP_PATH) -lapp -Wl,-R$(LIB_APP_PATH) -Wl,--enable-new-dtags

.PHONY: clean

all: main

main: main.o
	$(CC) -o $@ $^ $(CLFAGS) $(LDFLAGS) -t

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm *.o main
