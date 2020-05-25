SRCS += $(wildcard *.c)
SRCS += $(wildcard portable/GCC/ARM_CM4F/*.c)
SRCS += $(wildcard portable/MemMang/*.c)
OBJECTS := $(SRCS:.c=.o)
BINARY = librtos
CPPFLAGS = -Iinclude/
CPPFLAGS += -Iportable/GCC/ARM_CM4F/

PREFIX ?= arm-none-eabi-

CC			:= $(PREFIX)gcc
CXX			:= $(PREFIX)g++
LD			:= $(PREFIX)gcc
AR			:= $(PREFIX)ar
AS			:= $(PREFIX)as
OBJCOPY		:= $(PREFIX)objcopy
OBJDUMP		:= $(PREFIX)objdump
GDB			:= $(PREFIX)gdb
OPT			:= -Os
DEBUG		:= -ggdb3
CSTD		?= -std=c99
FP_FLAGS	?= -mfloat-abi=hard -mfpu=fpv4-sp-d16
ARCH_FLAGS	= -mthumb -mcpu=cortex-m4 $(FP_FLAGS)


.PHONY: shared

all: static
static: $(BINARY).a

%.a: $(OBJECTS)
	$(AR) $(OBJECTS) -o $*.a

%.o %.d: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o $*.o -c $*.c
