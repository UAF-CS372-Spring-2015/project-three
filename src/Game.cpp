// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Game.cpp

#include "Game.h"
#include "RandomWall.h"

Game::Game(): _window(std::make_shared<sf::RenderWindow>()), _player(std::make_shared<Player>()), _isPaused(false), _gameInputHandler(), _currentRoom(), _menu(this)
{
  std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
  _window->create(modes[0], "The Platformer");
  _window->setFramerateLimit(60);
  _menu.setup();
  buildRoom();
}

void Game::buildRoom()
{
  auto size = window()->getSize();
  auto randomWalls = RandomWalls();

  _currentRoom = std::make_shared<CoinRoom>();
  _currentRoom->setSize(size.x, size.y);
  // _currentRoom->setPosition(0,0);
  _currentRoom->spawn(_player, _currentRoom->getCenter());
  _currentRoom->generateContent();
  for(auto ii=0; ii<10; ++ii)
    randomWalls.generateContent(_currentRoom.get());
}

std::shared_ptr<sf::RenderWindow> Game::window()
{
  return _window;
}

void Game::run()
{
  initializeCommands();

  // keep track of the frametime
  sf::Clock frametime; // TODO: make this a global clock member for game?
  float deltaTime;

  // Menu menu(this);

  while (isRunning())
  {
      // get delta time for frame-rate depended movement
      deltaTime = frametime.restart().asSeconds();
      handleEvents();

      if(isPaused())
      {
        _menu.draw(deltaTime);
        // _menu.handleInput();
      }
      else
      {
        _currentRoom->update(deltaTime);
        drawEntities();
      }
  }

  exit();
}

bool Game::isRunning()
{
  return window()->isOpen();
}

void Game::pauseGame()
{
  _isPaused = !_isPaused;
}

bool Game::isPaused()
{
  return _isPaused;
}

void Game::exit()
{
  window()->close();
}

void Game::initializeCommands()
{
  _gameInputHandler.setExitCommand(std::make_shared<ExitCommand>(this));
  _gameInputHandler.setMoveCommand(std::make_shared<MovePlayerCommand>(_player.get())); // get() extracts value of shared pointer
  _gameInputHandler.setRebuildRoomCommand(std::make_shared<RebuildRoomCommand>(this));
  _gameInputHandler.setPauseCommand(std::make_shared<PauseCommand>(this)); // why this pointer?
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
      case sf::Event::MouseButtonReleased:
      {
        if (isPaused())
          _menu.handleInput(event);

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

void Game::drawEntities()
{
  window()->clear(sf::Color::Color(128,128,128));

  _currentRoom->draw(window());

  window()->display();
}

void Game::drawMenu(float deltaTime)
{
  drawMenu(deltaTime);
}
