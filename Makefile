CFLAGS =  -Wall -ansi -pedantic -O0 -g
all: hw1 hw1.o prog1Functions.o clean

hw1: prog1.c
	gcc $(CFLAGS) -o hw1 *.c

hw1.o: prog1.c
	gcc $(CFLAGS) -c -o hw1.o prog1.c

prog1Functions.o: prog1Functions.c
	gcc $(CFLAGS) -c -o prog1Functions.o prog1Functions.c

clean:
	rm -f *.o a.out
