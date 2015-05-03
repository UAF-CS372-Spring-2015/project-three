// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Screen.h

#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
#include "Game.h"

class Screen : public Game
{
public:
  ~Screen() = default;
  Screen();

  virtual void handleInput(sf::RenderWindow &window) = 0;
  virtual void update(sf::Time deltaTime) = 0;
  virtual void draw(sf::RenderWindow &window) = 0;
  
private:
	sf::RenderWindow _window;
};

#endif
