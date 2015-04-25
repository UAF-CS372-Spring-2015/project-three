#ifndef __THEPLATFORMER_INPUT_HANDLER
#define __THEPLATFORMER_INPUT_HANDLER

#include <SFML/Graphics.hpp>
#include <memory>
#include "Command.h"

class Game;

class GameInputHandler
{
public:
  std::shared_ptr<Command> handleInput(const sf::Event &);
  void setExitCommand(std::shared_ptr<Command>);
public:
  std::shared_ptr<Command> _exit;
};

#endif
