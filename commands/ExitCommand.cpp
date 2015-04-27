#include "../Game.h"
#include "ExitCommand.h"

ExitCommand::ExitCommand(Game * game)
{
  _game = game;
}

void ExitCommand::execute(bool pressed, const sf::Event &event)
{
  if (pressed)
    _game->exit();
}
