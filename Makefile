
CC=gcc
CFLAGS=-I. -I/opt/local/include/ -g3 -O0
LDFLAGS=-L/opt/local/lib -luv

default: mazikeen

mazikeen: src/m.o src/scanner.o src/parser.o
	gcc $(LDFLAGS) src/m.o src/scanner.o src/parser.o -o mazikeen

src/m.o: src/m.c src/mk.h
	$(CC) $(CFLAGS) -c src/m.c -o src/m.o

src/parser.o: src/parser.c src/mk.h
	$(CC) $(CFLAGS) -c src/parser.c -o src/parser.o

src/scanner.o: src/scanner.c src/mk.h
	$(CC) $(CFLAGS) -c src/scanner.c -o src/scanner.o

src/parser.c: src/language.c src/base.c
	cat src/language.c src/base.c > src/parser.c

src/language.c: src/language.inc.h src/lemon src/language.lemon
	cd src && ./lemon language.lemon

src/scanner.c: src/scanner.re src/scanner.h
	re2c -o src/scanner.c src/scanner.re

src/lemon: src/lemon.c
	gcc src/lemon.c -o src/lemon

clean:
	$(RM) src/*.o src/scanner.c src/language.c src/parser.c
