CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -std=c++14 -Wall
LDFLAGS=
# need to define this to be able to compile on Jacobs computer
JACOBFLAGS=-I /usr/local/include -L /usr/local/lib
SOURCES=Game.cpp Player.cpp

all: the_platformer

the_platformer:
	$(CC) $(CFLAGS) main.cpp $(SOURCES) -o $@

j:
	$(CC) $(JACOBFLAGS) $(CFLAGS) main.cpp $(SOURCES) -o $@
j_test:
	$(CC) $(JACOBFLAGS) $(CFLAGS) test.cpp $(SOURCES) -o $@


test:
	$(CC) $(CFLAGS) test.cpp $(SOURCES) -o $@

clean:
	rm the_platformer test j j_test
