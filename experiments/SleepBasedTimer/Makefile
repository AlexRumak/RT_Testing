CC=g++

CFLAGS=-std=c++23 -Wall -Werror -pedantic

PRODUCT=fib stat

all: $(PRODUCT)

fib: Fib.cpp Fib.hpp
	$(CC) $(CFLAGS) -o $@ $<

stat: Stats.cpp Stats.hpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PRODUCT)