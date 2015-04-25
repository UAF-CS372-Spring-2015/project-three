#include "Game.h"
#include "ExitCommand.h"

void ExitCommand::execute(Game & game)
{
  game.exit();
}
