// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// RebuildRoomCommand.cpp

#include "RebuildRoomCommand.h"

#include "../Game.h"

RebuildRoomCommand::RebuildRoomCommand(Game * game): _game(game)
{

}

void RebuildRoomCommand::execute(bool pressed, const sf::Event &event)
{
  if (pressed)
    _game->buildRoom();
}
