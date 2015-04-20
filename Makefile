CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -std=c++14 -Wall
LDFLAGS=
SOURCES=

all: release

release:
	$(CC) $(CFLAGS) main.cpp $(SOURCES) -o the_platformer_test

test:
	$(CC) $(CFLAGS) test.cpp $(SOURCES) -o the_platformer

clean:
	rm the_platformer the_platformer_test