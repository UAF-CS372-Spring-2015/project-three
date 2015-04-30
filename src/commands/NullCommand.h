// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// NullCommand.h

#ifndef NULL_COMMAND
#define NULL_COMMAND

#include "Command.h"

class NullCommand : public Command
{
public:
  virtual void execute(bool, const sf::Event &) override;
};

#endif
