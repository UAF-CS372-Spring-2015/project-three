#include <SFML/Graphics.hpp>
#include <memory>
using std::shared_ptr;
using std::make_shared;

#include "Game.h"

Game::Game(): _window(make_shared<sf::RenderWindow>()), _gameInputHandler(), _currentRoom()
{
  // , "The Platformer", )
  std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
  _window->create(modes[0], "The Platformer");
  _window->setFramerateLimit(60);

  auto size = window()->getSize();
  auto center = window()->getView().getCenter();

  _player.setPosition(center.x, center.y);

  _currentRoom.setSize(size.x - 100, size.y - 100);
  _currentRoom.setPosition(center.x, center.y);
}

bool Game::isRunning()
{
  return window()->isOpen();
}

void Game::run()
{
  initializeCommands();

  // Keep track of the frametime
  sf::Clock frametime;

  while (isRunning())
  {
      // Get delta time for frame-rate depended movement
      float dt = frametime.restart().asSeconds();

      handleEvents();
      drawEntities(dt);
  }

  exit();
}

void Game::drawEntities(float dt)
{

  window()->clear(sf::Color::Color(128,128,128));

  _player.draw(window(), dt);
  _coins.draw(window(), dt);
  _currentRoom.draw(window(), dt);

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
