CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -std=c++14 -Wall
LDFLAGS=
# need to define this to be able to compile on Jacobs computer
JACOBFLAGS=-I /usr/local/include -L /usr/local/lib
SOURCES=Game.cpp Player.cpp

all: release

release:
	$(CC) $(CFLAGS) main.cpp $(SOURCES) -o $@

j:
	$(CC) $(JACOBFLAGS) $(CFLAGS) main.cpp $(SOURCES) -o the_platformer_test
j_test:
	$(CC) $(JACOBFLAGS) $(CFLAGS) test.cpp $(SOURCES) -o the_platformer


test:
	$(CC) $(CFLAGS) test.cpp $(SOURCES) -o $@

clean:
	rm release test
