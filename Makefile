# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=clang++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CC) $(CFLAGS) main.cpp -o the_platformer

clean:
	rm the_platformer
