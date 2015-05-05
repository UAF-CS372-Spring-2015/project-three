CC=clang++
JACOBFLAGS=-I/usr/local/include
CFLAGS=$(JACOBFLAGS) -c -std=c++14 -Wall
LDFLAGS=-L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

GAMESOURCES=src/Game.cpp \
			src/GameInputHandler.cpp \
			src/commands/Command.cpp \
			src/commands/NullCommand.cpp \
			src/commands/ExitCommand.cpp \
			src/commands/MovePlayerCommand.cpp \
			src/commands/RebuildRoomCommand.cpp \
			src/commands/PauseCommand.cpp \
			src/Menu.cpp \
			src/Button.cpp \
			src/Entity.cpp \
			src/Player.cpp \
			src/Coin.cpp \
			src/Room.cpp \
			src/EmptyRoom.cpp \
			src/CoinRoom.cpp \
			src/RoomWall.cpp \
			src/Display.cpp

MAINSOURCES=src/main.cpp \
			$(GAMESOURCES)

TESTSOURCES=src/maintest.cpp \
			$(GAMESOURCES)

MAINOBJECTS=$(MAINSOURCES:.cpp=.o)
MAINEXECUTABLE=the_platformer

TESTOBJECTS=$(TESTSOURCES:.cpp=.o)
TESTEXECUTABLE=the_platformer_test

# tips on the makefile variables
# $@	name of target
# $<	name of first prerequisite
# $^	name of all prerequisites

all: $(MAINSOURCES) $(MAINEXECUTABLE)

test: $(TESTSOURCES) $(TESTEXECUTABLE)

$(MAINEXECUTABLE): $(MAINOBJECTS)
	$(CC) $(LDFLAGS) $(MAINOBJECTS) -o $@

$(TESTEXECUTABLE): $(TESTOBJECTS)
	$(CC) $(LDFLAGS) $(TESTOBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm the_platformer the_platformer_test src/*.o src/commands/*.o
