// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// PauseCommand.h

#ifndef PAUSECOMMAND_H
#define PAUSECOMMAND_H

#include "Command.h"

class Game; // TODO: why is this here? forward declaration? just include Game.h...?

class PauseCommand : public Command
{
public:
  PauseCommand(Game *game);
  virtual void execute(bool pressed, const sf::Event &event) override;
private:
  Game *_game; // TODO: Probably should be a unique pointer
};

#endif
