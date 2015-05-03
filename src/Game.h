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
#include "Menu.h"
#include "Player.h"
#include "Coin.h"
#include "Room.h"

class Game
{
public:
  ~Game() = default;
  Game();

  std::shared_ptr<sf::RenderWindow> window(); // TODO: Rename to getWindow()?
  void run(); // TODO: Rename to startGame()?
  bool isRunning();

  void pauseGame();
  bool isPaused(); // for implementing menus

  void exit(); // TODO: Rename endGame()?

  void initializeCommands(); // TODO: Do we need this? There will only be so omany commands.
  void handleEvents(); // TODO: Differentiate between events and input?

  void drawEntities(float deltaTime);
  void drawMenu(float deltaTime);

  void buildRoom();
  
private:
  std::shared_ptr<sf::RenderWindow> _window;
  std::shared_ptr<Player> _player;

  bool _isPaused;

  std::shared_ptr<Menu> _menu;

  GameInputHandler _gameInputHandler;

  std::shared_ptr<Room> _currentRoom;

  std::vector<Coin> _coins; // TODO: Room should keep track of its coins, not the game
};

#endif
