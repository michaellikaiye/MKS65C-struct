all: struct.o
	gcc -o hello struct.o

struct.o:struct.c
	gcc -c struct.c

run:
	./hello

clear:
	rm *.o
