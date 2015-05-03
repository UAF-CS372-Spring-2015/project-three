// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Command.h

#ifndef COMMAND_H
#define COMMAND_H

#include <SFML/Graphics.hpp>
#include "../Game.h"

class Command
{
public:
  virtual ~Command() = default;
  virtual void execute(bool, const sf::Event &event) = 0;
private:
};

#endif
