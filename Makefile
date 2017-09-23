
CC=gcc
CFLAGS=-I. -I/opt/local/include/ -g3 -O0
LDFLAGS=-L/opt/local/lib -luv

default: mazikeen

mazikeen: src/m.o src/parser/scanner.o src/parser/parser.o
	gcc $(LDFLAGS) src/m.o src/parser/scanner.o src/parser/parser.o -o mazikeen

src/m.o: src/m.c src/mk.h
	$(CC) $(CFLAGS) -c src/m.c -o src/m.o

src/parser/parser.o: src/parser/parser.c src/mk.h
	$(CC) $(CFLAGS) -c src/parser/parser.c -o src/parser/parser.o

src/parser/scanner.o: src/parser/scanner.c src/mk.h
	$(CC) $(CFLAGS) -c src/parser/scanner.c -o src/parser/scanner.o

src/parser/parser.c: src/parser/language.c src/parser/base.c
	cat src/parser/language.c src/parser/base.c > src/parser/parser.c

src/parser/language.c: src/parser/language.inc.h src/parser/lemon src/parser/language.lemon
	cd src/parser && ./lemon language.lemon

src/parser/scanner.c: src/parser/scanner.re src/parser/scanner.h
	re2c -o src/parser/scanner.c src/parser/scanner.re

src/parser/lemon: src/parser/lemon.c
	gcc src/parser/lemon.c -o src/parser/lemon

clean:
	$(RM) src/*.o src/scanner.c src/language.c src/parser.c
