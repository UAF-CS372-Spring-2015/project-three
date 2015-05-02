// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Menu.h

#ifndef MENU_H
#define MENU_H

#include <vector>
#include "Game.h"
#include "Button.h"

class Menu : public Game
{
public:
  ~Menu() = default;
  Menu();

  void handleInput();
  void update(float deltaTime);
  void draw(float deltaTime);

private:
  std::vector<Button> _buttons;

};

#endif
