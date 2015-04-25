CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -std=c++14 -Wall
LDFLAGS=
SOURCES=Game.cpp Player.cpp

all: release

release:
	$(CC) $(CFLAGS) main.cpp $(SOURCES) -o $@

test:
	$(CC) $(CFLAGS) test.cpp $(SOURCES) -o $@

clean:
	rm release test
