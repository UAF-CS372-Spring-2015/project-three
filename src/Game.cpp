// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Game.cpp

#include "Game.h"

Game::Game(): _window(std::make_shared<sf::RenderWindow>()), _player(std::make_shared<Player>()), _currentRoom(), _gameInputHandler()
{
  std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
  _window->create(modes[0], "The Platformer");
  _window->setFramerateLimit(60);

  buildRoom();
}

void Game::buildRoom()
{
  auto size = window()->getSize();
  auto center = window()->getView().getCenter();

  _currentRoom = std::make_shared<CoinRoom>();
  _currentRoom->setSize(size.x, size.y);
  _currentRoom->setPosition(center.x, center.y);
  _currentRoom->generateContent();
  _currentRoom->spawn(_player, _currentRoom->getCenter());
}

std::shared_ptr<sf::RenderWindow> Game::window()
{
  return _window;
}

void Game::run()
{
  initializeCommands();

  // keep track of the frametime
  sf::Clock frametime;

  while (isRunning())
  {
      // get delta time for frame-rate depended movement
      float dt = frametime.restart().asSeconds();

      handleEvents();
      drawEntities(dt);
  }

  exit();
}

bool Game::isRunning()
{
  return window()->isOpen();
}

void Game::exit()
{
  window()->close();
}

void Game::initializeCommands()
{
  _gameInputHandler.setExitCommand(std::make_shared<ExitCommand>(this));
  _gameInputHandler.setMoveCommand(std::make_shared<MovePlayerCommand>(_player.get()));
  _gameInputHandler.setRebuildRoomCommand(std::make_shared<RebuildRoomCommand>(this));
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

void Game::drawEntities(float dt)
{
  window()->clear(sf::Color::Color(128,128,128));

  _currentRoom->draw(window(), dt);

  window()->display();
}
