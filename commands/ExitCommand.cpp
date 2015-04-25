#include "../Game.h"
#include "ExitCommand.h"

ExitCommand::ExitCommand(Game * game)
{
  _game = game;
}

void ExitCommand::execute(const sf::Event &event)
{
  _game->exit();
}
