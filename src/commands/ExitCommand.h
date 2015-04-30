// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// ExitCommand.h

#ifndef EXIT_COMMAND
#define EXIT_COMMAND

#include "Command.h"

class Game;

class ExitCommand : public Command
{
public:
  ExitCommand(Game *);
  virtual void execute(bool, const sf::Event &) override;
private:
  Game *_game; // TODO: Probably shoudl be a unique pointer
};

#endif
