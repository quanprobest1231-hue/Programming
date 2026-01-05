# Compiler và flags
CC := gcc
CFLAGS := -Wall -I.
ASFLAGS :=

# Files
SRC := main.c hello.c
PRE := $(SRC:.c=.i)
ASM := $(SRC:.c=.s)
OBJ := $(SRC:.c=.o)
EXE := hellomake

.PHONY: all clean

# Target chính
all: $(EXE)

# 1️⃣ Linking: từ .o -> executable
$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

# 2️⃣ Assembling: từ .s -> .o
%.o: %.s
	$(CC) -c $< -o $@

# 3️⃣ Compilation: từ .i -> .s
%.s: %.i
	$(CC) -S $< -o $@

# 4️⃣ Preprocessing: từ .c -> .i
%.i: %.c
	$(CC) -E $< -o $@

# Xóa file build
clean:
	rm -f $(OBJ) $(PRE) $(ASM) $(EXE)
