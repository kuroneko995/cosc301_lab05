CC=clang
CFLAGS=-g -Wall

all: lab05 

lab05: players.o
	$(CC) $(CFLAGS) -o $@ players.o -lm

.PHONY: clean
clean:
	rm -f *.o lab05

.c.o:
	$(CC) -c $(CFLAGS) $<
