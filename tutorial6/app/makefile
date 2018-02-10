CFLAGS = -g -Wall
LIB_APP_PATH = ../lib
INCLUDES = -I $(LIB_APP_PATH)
LDFLAGS = -L $(LIB_APP_PATH) -lapp

all: main

main: main.o
	$(CC) -o $@ $^ $(CLFAGS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean

clean:
	rm *.o main
