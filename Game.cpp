#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Game.h"

Game::Game(): _window(make_shared<sf::RenderWindow>(sf::VideoMode(500,500), "The Platformer")), _gameInputHandler()
{
}

void Game::initializeCommands()
{
  _gameInputHandler.setExitCommand(make_shared<ExitCommand>(this));
  // TODO: When we implement the player we should pass it to this command
  _gameInputHandler.setMovePlayerCommand(make_shared<MovePlayerCommand>());
}

shared_ptr<Command> Game::handleGameInput(sf::Event &event)
{
  return _gameInputHandler.handleInput(event);
}

shared_ptr<sf::RenderWindow> Game::window()
{
  return _window;
}

void Game::exit()
{
  window()->close();
}
