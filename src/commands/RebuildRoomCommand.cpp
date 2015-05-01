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
