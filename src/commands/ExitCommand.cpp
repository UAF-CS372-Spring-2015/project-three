// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// ExitCommand.cpp

#include "../Game.h"
#include "ExitCommand.h"

ExitCommand::ExitCommand(Game *game)
{
  _game = game;
}

void ExitCommand::execute(bool pressed, const sf::Event &event)
{
  if (pressed)
    _game->exit();
}
