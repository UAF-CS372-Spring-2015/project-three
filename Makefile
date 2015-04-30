CC=clang++
JACOBFLAGS=-I/usr/local/include -L/usr/local/lib
CFLAGS=$(JACOBFLAGS) -c -std=c++14 -Wall 
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp \
		Game.cpp \
		GameInputHandler.cpp \
		commands/Command.cpp \
		commands/NullCommand.cpp \
		commands/ExitCommand.cpp \
		commands/MovePlayerCommand.cpp \
		Entity.cpp \
		Player.cpp \
		Coin.cpp \
		Room.cpp \
		EmptyRoom.cpp \
		CoinRoom.cpp

OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=the_platformer

# tips on the makefile variables
# $@	name of target
# $<	name of first prerequisite
# $^	name of all prerequisites

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm the_platformer test *.o commands/*.o
