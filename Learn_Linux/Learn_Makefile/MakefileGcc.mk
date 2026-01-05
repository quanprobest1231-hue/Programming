# Đánh dấu target ảo
.PHONY: all clean hellomake hello test

# Compiler và flags
CC := gcc
CFLAGS := -I.

# File include
INC_FILES := hello.h

# Rule chung: build .o từ .c
%.o: %.c $(INC_FILES)
	$(CC) -c -o $@ $< $(CFLAGS)

# Target test: in ra biến đặc biệt của Make
test: hello.h hello.c
	@echo "Target: $@"
	@echo "Dependencies: $^"
	@echo "First dependency: $<"

# Target chính: hellomake
hellomake: main.o hello.o
	$(CC) -o hellomake main.o hello.o $(CFLAGS)

# Target hello (biên dịch trực tiếp)
hello:
	$(CC) -o hello main.c hello.c $(CFLAGS)

# Xóa file build
clean:
	rm -f *.o hellomake hello
