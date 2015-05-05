// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// PauseCommand.cpp

#include "PauseCommand.h"
#include "../Game.h"

PauseCommand::PauseCommand(Game *game)
{
  _game = game;
}

void PauseCommand::execute(bool pressed, const sf::Event &event)
{
  if (pressed)
    _game->pauseGame();
}