
CC=gcc
CFLAGS=-I. -I/opt/local/include/ -g3 -O0
LDFLAGS=-L/opt/local/lib -luv

default: mazikeen

mazikeen: src/m.o src/parser/scanner.o src/parser/parser.o src/executor/executor.o src/executor/create-coll.o \
		src/executor/open-db.o src/executor/open-coll.o \
		src/executor/insert.o src/engine/memory.o src/engine/packer.o src/engine/writer.o src/engine/reader.o
	gcc $(LDFLAGS) src/m.o src/parser/scanner.o src/parser/parser.o src/executor/executor.o \
		src/executor/create-coll.o src/executor/open-db.o src/executor/open-coll.o src/executor/insert.o \
		src/engine/memory.o src/engine/packer.o src/engine/writer.o src/engine/reader.o -o mazikeen

src/m.o: src/m.c src/mk.h
	$(CC) $(CFLAGS) -c src/m.c -o src/m.o

# engine
src/engine/memory.o: src/engine/memory.c src/mk.h src/engine/memory.h src/engine/engine.h
	$(CC) $(CFLAGS) -c src/engine/memory.c -o src/engine/memory.o

src/engine/packer.o: src/engine/packer.c src/mk.h src/engine/packer.h src/engine/engine.h
	$(CC) $(CFLAGS) -c src/engine/packer.c -o src/engine/packer.o

src/engine/writer.o: src/engine/writer.c src/mk.h src/engine/writer.h src/engine/engine.h
	$(CC) $(CFLAGS) -c src/engine/writer.c -o src/engine/writer.o

src/engine/reader.o: src/engine/reader.c src/mk.h src/engine/reader.h src/engine/engine.h
	$(CC) $(CFLAGS) -c src/engine/reader.c -o src/engine/reader.o

# executor
src/executor/executor.o: src/executor/executor.c src/mk.h src/executor/executor.h
	$(CC) $(CFLAGS) -c src/executor/executor.c -o src/executor/executor.o

src/executor/create-coll.o: src/executor/create-coll.c src/executor/executor.h
	$(CC) $(CFLAGS) -c src/executor/create-coll.c -o src/executor/create-coll.o

src/executor/open-db.o: src/executor/open-db.c src/executor/executor.h
	$(CC) $(CFLAGS) -c src/executor/open-db.c -o src/executor/open-db.o

src/executor/open-coll.o: src/executor/open-coll.c src/executor/executor.h
	$(CC) $(CFLAGS) -c src/executor/open-coll.c -o src/executor/open-coll.o

src/executor/insert.o: src/executor/insert.c src/executor/executor.h
	$(CC) $(CFLAGS) -c src/executor/insert.c -o src/executor/insert.o

# parser
src/parser/parser.o: src/parser/parser.c src/mk.h src/parser/parser.h
	$(CC) $(CFLAGS) -c src/parser/parser.c -o src/parser/parser.o

src/parser/scanner.o: src/parser/scanner.c src/mk.h src/parser/parser.h
	$(CC) $(CFLAGS) -c src/parser/scanner.c -o src/parser/scanner.o

src/parser/parser.c: src/parser/language.c src/parser/base.c
	cat src/parser/language.c src/parser/base.c > src/parser/parser.c

src/parser/language.c: src/parser/language.inc.h src/parser/lemon src/parser/language.lemon
	cd src/parser && ./lemon language.lemon

src/parser/scanner.c: src/parser/scanner.re src/parser/scanner.h src/parser/parser.h
	re2c -o src/parser/scanner.c src/parser/scanner.re

src/parser/lemon: src/parser/lemon.c
	gcc src/parser/lemon.c -o src/parser/lemon

clean:
	$(RM) src/*.o src/parser/*.o src/executor/*.o src/engine/*.o src/parser/scanner.c src/parser/language.c src/parser/parser.c
