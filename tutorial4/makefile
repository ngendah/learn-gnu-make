INCLUDES = -I ../includes
SRC_PATH = ./src
CFLAGS = -g
OBJECTS = $(SRC_PATH)/main.o

all: main

main: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm $(SRC_PATH)/*.o main
