INCLUDES := -I ../includes
SRC_PATH := ./src
CFLAGS := -g
OBJECTS := $(SRC_PATH)/main.o

.PHONY: clean

all: main

main: $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm $(SRC_PATH)/*.o main
