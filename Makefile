CC=clang++
CFLAGS=$(JFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -std=c++14 -Wall
LDFLAGS=
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

Command.o: commands/Command.cpp
	$(CC) $(CFLAGS) -c $^

ExitCommand.o: commands/ExitCommand.cpp
	$(CC) $(CFLAGS) -c $^

NullCommand.o: commands/NullCommand.cpp
	$(CC) $(CFLAGS) -c $^

MovePlayerCommand.o: commands/MovePlayerCommand.cpp
	$(CC) $(CFLAGS) -c $^

test:
	$(CC) $(CFLAGS) test.cpp $(SOURCES) -o $@

clean:
	rm the_platformer test j j_test *.o commands/*.gch
