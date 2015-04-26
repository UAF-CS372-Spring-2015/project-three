#include <SFML/Graphics.hpp>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Game.h"

Game::Game(): _window(make_shared<sf::RenderWindow>(sf::VideoMode(500,500), "The Platformer")), _gameInputHandler()
{
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
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  window()->clear();
  window()->draw(shape);
  window()->display();
}

void Game::initializeCommands()
{
  _gameInputHandler.setExitCommand(make_shared<ExitCommand>(this));
  // TODO: When we implement the player we should pass it to this command
  _gameInputHandler.setMovePlayerCommand(make_shared<MovePlayerCommand>());
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
        gameCommand->execute(event);
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
