SRCS := $(wildcard *.c)
OBJECTS := $(SRCS:.c=.o)
BINARY = blink
OPENCM3_DIR = ../libopencm3
OPENCM3_LIB = opencm3_stm32f4
LDSCRIPT = ./stm32f4-discovery.ld
DEFS = -DSTM32F4

PREFIX ?= arm-none-eabi-

CC		:= $(PREFIX)gcc
CXX		:= $(PREFIX)g++
LD		:= $(PREFIX)gcc
AR		:= $(PREFIX)ar
AS		:= $(PREFIX)as
OBJCOPY		:= $(PREFIX)objcopy
OBJDUMP		:= $(PREFIX)objdump
GDB		:= $(PREFIX)gdb
STFLASH		= $(shell which st-flash)
OPT		:= -Os
DEBUG		:= -ggdb3
CSTD		?= -std=c99
FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH_FLAGS	= -mthumb -mcpu=cortex-m4 $(FP_FLAGS)


DEFS		+= -I$(OPENCM3_DIR)/include
LDFLAGS		+= -L$(OPENCM3_DIR)/lib
LDLIBS		+= -l$(OPENCM3_LIB)
LDLIBS		+= -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group

TGT_CPPFLAGS	+= -MD
TGT_CPPFLAGS	+= -Wall -Wundef
TGT_CPPFLAGS	+= $(DEFS)

TGT_CFLAGS	+= $(OPT) $(CSTD) $(DEBUG)
TGT_CFLAGS	+= $(ARCH_FLAGS)
TGT_CFLAGS	+= -Wextra -Wshadow -Wimplicit-function-declaration
TGT_CFLAGS	+= -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes
TGT_CFLAGS	+= -fno-common -ffunction-sections -fdata-sections

TGT_LDFLAGS		+= --static -nostartfiles
TGT_LDFLAGS		+= -T$(LDSCRIPT)
TGT_LDFLAGS		+= $(ARCH_FLAGS) $(DEBUG)
TGT_LDFLAGS		+= -Wl,-Map=$*.map -Wl,--cref
TGT_LDFLAGS		+= -Wl,--gc-sections

.PHONY: elf bin clean

all: elf bin
elf: $(BINARY).elf
bin: $(BINARY).bin

%.bin: %.elf
	$(OBJCOPY) -Obinary $*.elf $*.bin

%.elf: $(OBJECTS)
	$(LD) $(TGT_LDFLAGS) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $*.elf

%.o %.d: %.c
	$(CC) $(TGT_CFLAGS) $(CFLAGS) $(TGT_CPPFLAGS) $(CPPFLAGS) -o $*.o -c $*.c

flash:
	st-flash write $(BINARY).bin 0x8000000

clean:
	rm -f *.d *.o *.bin *.elf *.map
