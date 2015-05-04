// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// GameInputHandler.h

#ifndef GAME_INPUT_HANDLER_H
#define GAME_INPUT_HANDLER_H


#include <SFML/Window/Keyboard.hpp>
#include <memory>
#include <map>
#include <string>
#include "commands/Command.h"
#include "commands/NullCommand.h"
#include "commands/ExitCommand.h"
#include "commands/MovePlayerCommand.h"
#include "commands/RebuildRoomCommand.h"
#include "commands/PauseCommand.h"

//#include "Game.h"

class GameInputHandler
{
public:
  ~GameInputHandler() = default;
  GameInputHandler();
  std::shared_ptr<Command> handleInput(const sf::Event &event);
  void setExitCommand(std::shared_ptr<Command> command);
  void setMoveCommand(std::shared_ptr<Command> command);
  void setRebuildRoomCommand(std::shared_ptr<Command> command );
  void setPauseCommand(std::shared_ptr<Command> command);

  void addCommand(sf::Keyboard::Key, std::shared_ptr<Command>);
public: // TODO: this should be private?
  std::map<sf::Keyboard::Key, std::shared_ptr<Command>> _commands;
  std::shared_ptr<Command> _null;
};

#endif
