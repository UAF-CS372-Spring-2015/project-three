#include "Game.h"
#include "ExitCommand.h"

void ExitCommand::execute(Game & game, const sf::Event &event)
{
  game.exit();
}
