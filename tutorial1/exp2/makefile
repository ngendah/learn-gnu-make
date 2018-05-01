SRCS := main.c add.c subtract.c
OBJECTS := $(SRCS:.c=.o)
LDFLAGS :=
CFLAGS := -Wall -g

.PHONY: clean

all: print main

print:
	@echo "OBJECTS are: $(OBJECTS)"

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJECTS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
main.o: add.o subtract.o

clean:
	rm *.o main
