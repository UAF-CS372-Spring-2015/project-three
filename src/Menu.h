// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Menu.h

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>

//#include "Game.h"
#include "Button.h"

class Game;

class Menu
{
public:
  ~Menu() = default;
  Menu(Game *game);

  void handleInput();
  void update(float deltaTime);
  void draw(float deltaTime);

private:
  Game *_game;
  std::vector<std::shared_ptr<Button>> _buttons;

};

#endif
