# (C) Antonio Maulucci 2026

CC          ?= gcc
CC_X86_64   ?= x86_64-linux-gnu-gcc

SRC         := main.c
TARGET      := main
TARGET_X86  := main_x86_64

CFLAGS      :=
DEBUG_CFLAGS := -Wall -Wextra -g3 -O0 -fno-omit-frame-pointer

.PHONY: all clean debug run onarm run-x86_64 gdb-x86_64

all: $(TARGET)

# build nativo (ARM)
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

# build x86_64 su ARM (cross compile)
$(TARGET_X86): $(SRC)
	$(CC_X86_64) $(CFLAGS) -o $@ $<

debug: CFLAGS := $(DEBUG_CFLAGS)
debug: $(TARGET)

run: $(TARGET)
	./$(TARGET)

# Compila x86_64 con flag debug
onarm: CFLAGS := $(DEBUG_CFLAGS)
onarm: $(TARGET_X86)

# Esegue x86_64 tramite QEMU user-mode (serve qemu-x86_64)
run-x86_64: $(TARGET_X86)
	# qemu-x86_64 ./$(TARGET_X86)
	qemu-x86_64 -L /usr/x86_64-linux-gnu ./$(TARGET_X86)

# Debug x86_64 su ARM: qemu gdbstub + gdb-multiarch (in due terminali)
gdb-x86_64: $(TARGET_X86)
	@echo "Terminale 1: qemu-x86_64 -g 1234 ./$(TARGET_X86)"
	@echo "Terminale 2: gdb-multiarch ./$(TARGET_X86)"
	@echo "  (gdb) set architecture i386:x86-64"
	@echo "  (gdb) target remote :1234"
	@echo "  (gdb) b main"
	@echo "  (gdb) c"

clean:
	rm -f $(TARGET) $(TARGET_X86)
