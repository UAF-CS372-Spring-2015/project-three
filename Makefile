CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -std=c++14 -Wall
LDFLAGS=
# need to define this to be able to compile on Jacobs computer
JACOBFLAGS=-I /usr/local/include -L /usr/local/lib
SOURCES=NullCommand.o ExitCommand.o Command.o GameInputHandler.o Game.cpp Player.cpp

all: the_platformer

the_platformer: main.cpp $(SOURCES)
	$(CC) $(CFLAGS) main.cpp $(SOURCES) -o $@

GameInputHandler.o: GameInputHandler.cpp
	$(CC) $(CFLAGS) -c $^

Command.o: Command.cpp
	$(CC) $(CFLAGS) -c $^

ExitCommand.o: Command.h ExitCommand.cpp
	$(CC) $(CFLAGS) -c $^

NullCommand.o: Command.h NullCommand.cpp
	$(CC) $(CFLAGS) -c $^

j:
	$(CC) $(JACOBFLAGS) $(CFLAGS) main.cpp $(SOURCES) -o $@
j_test:
	$(CC) $(JACOBFLAGS) $(CFLAGS) test.cpp $(SOURCES) -o $@


test:
	$(CC) $(CFLAGS) test.cpp $(SOURCES) -o $@

clean:
	rm the_platformer test j j_test
