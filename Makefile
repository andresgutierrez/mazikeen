
CC=gcc
CFLAGS=-I. -I/opt/local/include/ -g3 -O0
LDFLAGS=-L/opt/local/lib -luv

default: mazikeen

mazikeen: m.o scanner.o language.o
	gcc $(LDFLAGS) m.o scanner.o language.o -o mazikeen

m.o:
	$(CC) $(CFLAGS) -c m.c

language.o:
	$(CC) $(CFLAGS) -c language.c

scanner.o: scanner.c
	$(CC) $(CFLAGS) -c scanner.c

scanner.c:
	re2c -o scanner.c scanner.re

clean:
	$(RM) *.o scanner.c
