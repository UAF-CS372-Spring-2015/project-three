// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Game.h

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory> // for shared_ptr and make_shared
#include <vector> // for vector
#include "GameInputHandler.h"
#include "Player.h"
#include "Coin.h"
#include "EmptyRoom.h"
#include "CoinRoom.h"

class Game
{
public:
  ~Game() = default;
  Game();

  std::shared_ptr<sf::RenderWindow> window();
  void run();
  bool isRunning();
  void exit();

  void initializeCommands(); // TODO: Do we need this?
  void handleEvents();

  void drawEntities(float dt);
  void buildRoom();
  
private:
  std::shared_ptr<sf::RenderWindow> _window;
  std::shared_ptr<Player> _player;

  std::shared_ptr<Room> _currentRoom;

  GameInputHandler _gameInputHandler;
  std::vector<Coin> _coins;
};

#endif
