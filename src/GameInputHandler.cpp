// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// GameInputHandler.cpp

#include "GameInputHandler.h"
#include "commands/NullCommand.h"

GameInputHandler::GameInputHandler():_null(std::make_shared<NullCommand>())
{
}

void GameInputHandler::setExitCommand(std::shared_ptr<Command> command)
{
  addCommand(sf::Keyboard::Escape, command);
}

void GameInputHandler::setMoveCommand(std::shared_ptr<Command> command)
{
  addCommand(sf::Keyboard::Up, command);
  addCommand(sf::Keyboard::Down, command);
  addCommand(sf::Keyboard::Left, command);
  addCommand(sf::Keyboard::Right, command);
  addCommand(sf::Keyboard::W, command);
  addCommand(sf::Keyboard::A, command);
  addCommand(sf::Keyboard::S, command);
  addCommand(sf::Keyboard::D, command);
}

void GameInputHandler::setRebuildRoomCommand(std::shared_ptr<Command> command)
{
  addCommand(sf::Keyboard::Space, command);
}

void GameInputHandler::setPauseCommand(std::shared_ptr<Command> command)
{
  addCommand(sf::Keyboard::P, command);
}

void GameInputHandler::addCommand(sf::Keyboard::Key name, std::shared_ptr<Command> command)
{
  _commands[name] = command;
}

std::shared_ptr<Command> GameInputHandler::handleInput(const sf::Event &event)
{
  auto it = _commands.find(event.key.code);
  if (it == _commands.end())
    return _null;

  return it->second;
}
