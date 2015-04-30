CC=clang++
JACOBFLAGS=-I/usr/local/include 
CFLAGS=$(JACOBFLAGS) -c -std=c++14 -Wall 
LDFLAGS=-L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system

GAMESOURCES=Game.cpp \
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

MAINSOURCES=main.cpp \
			$(GAMESOURCES)

TESTSOURCES=maintest.cpp \
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
	rm the_platformer the_platformer_test *.o commands/*.o
