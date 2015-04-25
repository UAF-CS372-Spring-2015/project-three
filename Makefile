CC=clang++
CFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -std=c++14 -Wall
LDFLAGS=
# need to define this to be able to compile on Jacobs computer
JACOBFLAGS=-I /usr/local/include -L /usr/local/lib
SOURCES=MovePlayerCommand.o \
				NullCommand.o \
				ExitCommand.o \
				Command.o \
				GameInputHandler.o \
				Game.cpp \
				Player.cpp

all: the_platformer

the_platformer: main.cpp $(SOURCES)
	$(CC) $(CFLAGS) main.cpp $(SOURCES) -o $@

GameInputHandler.o: GameInputHandler.cpp
	$(CC) $(CFLAGS) -c $^

Command.o: commands/Command.h commands/Command.cpp
	$(CC) $(CFLAGS) -c $^

ExitCommand.o: commands/Command.h commands/ExitCommand.h commands/ExitCommand.cpp
	$(CC) $(CFLAGS) -c $^

NullCommand.o: commands/Command.h commands/NullCommand.h commands/NullCommand.cpp
	$(CC) $(CFLAGS) -c $^

MovePlayerCommand.o: commands/Command.h commands/MovePlayerCommand.h commands/MovePlayerCommand.cpp
	$(CC) $(CFLAGS) -c $^

j:
	$(CC) $(JACOBFLAGS) $(CFLAGS) main.cpp $(SOURCES) -o $@
j_test:
	$(CC) $(JACOBFLAGS) $(CFLAGS) test.cpp $(SOURCES) -o $@


test:
	$(CC) $(CFLAGS) test.cpp $(SOURCES) -o $@

clean:
	rm the_platformer test j j_test *.o commands/*.o commands/*.gch
