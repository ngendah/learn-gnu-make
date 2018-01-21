CFLAGS = -fPIC -Wall -Wextra -g
LDFLAGS = -shared
INC_DIR = include
SRC_DIR = src/
OBJECTS = $(SRC_DIR)/lib.o

all: lib

lib: $(OBJECTS)
	$(CC) -o "$@.so" $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -I $(INC_DIR) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm $(SRC_DIR)*.o lib.so
