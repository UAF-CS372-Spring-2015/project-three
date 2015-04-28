#include <SFML/Graphics.hpp>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Game.h"

Game::Game(): _window(make_shared<sf::RenderWindow>()), _gameInputHandler()
{
  // , "The Platformer", )
  std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
  _window->create(modes[0], "The Platformer");
  _window->setFramerateLimit(60);
}

bool Game::isRunning()
{
  return window()->isOpen();
}

void Game::run()
{
  initializeCommands();

  while (isRunning())
  {
      handleEvents();
      drawEntities();
  }

  exit();
}

void Game::drawEntities()
{
  window()->clear(sf::Color::Color(128,128,128));
  _player.draw(window());
  _coins.draw(window());
  // window()->draw();
  window()->display();
}

void Game::initializeCommands()
{
  _gameInputHandler.setExitCommand(make_shared<ExitCommand>(this));
  // TODO: When we implement the player we should pass it to this command
  _gameInputHandler.setMovePlayerCommand(make_shared<MovePlayerCommand>(&_player));
}

void Game::handleEvents()
{
  sf::Event event;
  while (window()->pollEvent(event))
  {
    switch (event.type)
    {
      case sf::Event::Closed:
      {
        exit();
        break;
      }
      case sf::Event::KeyPressed:
      {
        auto gameCommand = _gameInputHandler.handleInput(event);
        gameCommand->execute(true, event);
        break;
      }
      case sf::Event::KeyReleased:
      {
        auto gameCommand = _gameInputHandler.handleInput(event);
        gameCommand->execute(false, event);
        break;
      }
      default:
      {
        break;
      }
    }
  }
}

shared_ptr<sf::RenderWindow> Game::window()
{
  return _window;
}

void Game::exit()
{
  window()->close();
}
