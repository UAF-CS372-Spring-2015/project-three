// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// MovePlayerCommand.h

#ifndef MOVE_PLAYER_COMMAND
#define MOVE_PLAYER_COMMAND

#include "Command.h"

class MovePlayerCommand : public Command
{
public:
  MovePlayerCommand(Player *);
  virtual void execute(bool pressed, const sf::Event &event) override;
private:
  Player *_player; // TODO: We probably want a unique pointer here
};

#endif
