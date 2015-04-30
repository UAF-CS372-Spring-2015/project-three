// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// GameInputHandler.h

#ifndef GAME_INPUT_HANDLER
#define GAME_INPUT_HANDLER

#include <SFML/Window/Keyboard.hpp>
#include <memory>
#include "commands/Command.h"
#include "commands/NullCommand.h"
#include "commands/ExitCommand.h"
#include "commands/MovePlayerCommand.h"

class Game;

class GameInputHandler
{
public:
  GameInputHandler(): _null(std::make_shared<NullCommand>()) {}
  std::shared_ptr<Command> handleInput(const sf::Event &);
  void setExitCommand(std::shared_ptr<Command>);
  void setMovePlayerCommand(std::shared_ptr<Command>);
public:
  std::shared_ptr<Command> _null;
  std::shared_ptr<Command> _exit;
  std::shared_ptr<Command> _movePlayer;
};

#endif
