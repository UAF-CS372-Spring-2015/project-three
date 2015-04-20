CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -std=c++14

all:
	$(CC) $(CFLAGS) main.cpp -o the_platformer

test:
	$(CC) $(CFLAGS) test.cpp -o the_platformer_test

clean:
	rm the_platformer the_platformer_test