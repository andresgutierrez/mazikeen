
CC=gcc
CFLAGS=-I. -I/opt/local/include/ -g3 -O0
LDFLAGS=-L/opt/local/lib -luv

default: mazikeen

mazikeen: m.o scanner.o parser.o
	gcc $(LDFLAGS) m.o scanner.o parser.o -o mazikeen

m.o: m.c mk.h
	$(CC) $(CFLAGS) -c m.c

parser.o: parser.c mk.h
	$(CC) $(CFLAGS) -c parser.c

scanner.o: scanner.c mk.h
	$(CC) $(CFLAGS) -c scanner.c

parser.c: language.c base.c
	cat language.c base.c > parser.c

language.c: language.inc.h
	./lemon language.lemon

scanner.c: scanner.re scanner.h
	re2c -o scanner.c scanner.re

lemon: lemon.c
	gcc lemon.c -o lemon

clean:
	$(RM) *.o scanner.c language.c parser.c
