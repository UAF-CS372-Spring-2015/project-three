#include "GameInputHandler.h"
#include "ExitCommand.h"
using std::shared_ptr;

void GameInputHandler::setExitCommand(std::shared_ptr<Command> command)
{
  _exit = command;
}

shared_ptr<Command> GameInputHandler::handleInput(const sf::Event &event)
{
  switch(event.key.code)
  {
    case sf::Keyboard::Escape:
      return _exit;
      break;
  }

  return NULL;
}
