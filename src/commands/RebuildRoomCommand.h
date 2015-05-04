// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// RebuildRoomCommand.h

#ifndef REBUILD_ROOM_COMMAND_H
#define REBUILD_ROOM_COMMAND_H

#include "Command.h"

class Game;

class RebuildRoomCommand : public Command
{
public:
  RebuildRoomCommand(Game *);
  virtual void execute(bool, const sf::Event &) override;
private:
  Game *_game; // TODO: Probably should be a unique pointer
};

#endif
