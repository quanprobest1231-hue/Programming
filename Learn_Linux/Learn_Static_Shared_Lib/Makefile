# Build static library
static:
	ar rcs lib/static/libhello.a obj/helloQuan.o obj/helloWorld.o

# Build shared library
shared:
	gcc -fPIC -c src/helloQuan.c -I./inc -o obj/helloQuan.o
	gcc -fPIC -c src/helloWorld.c -I./inc -o obj/helloWorld.o
	gcc -shared -o lib/shared/libhello.so obj/helloQuan.o obj/helloWorld.o

# Link executable với static library
link_static:
	gcc obj/main.o -Llib/static -lhello -o bin/exam

# Link executable với shared library
link_shared:
	gcc obj/main.o -Llib/shared -lhello -o bin/exam_shared

# Biên dịch tất cả .c thành .o
all:
	gcc -c main.c -o obj/main.o -I./inc
	gcc -c src/helloQuan.c -o obj/helloQuan.o -I./inc
	gcc -c src/helloWorld.c -o obj/helloWorld.o -I./inc

# Xóa file build
clean:
	rm -rf obj/* bin/*