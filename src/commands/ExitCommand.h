// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// ExitCommand.h

#ifndef EXIT_COMMAND
#define EXIT_COMMAND

#include "Command.h"

class ExitCommand : public Command
{
public:
  ExitCommand(Game *game);
  virtual void execute(bool pressed, const sf::Event &event) override;
private:
  Game *_game; // TODO: Probably should be a unique pointer
};

#endif
