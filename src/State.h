// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// State.h

#ifndef STATE_H
#define STATE_H

#include "Game.h"

#include <SFML/Graphics.hpp>

class State : public Game
{
public:
  ~State() = default;
  State();

  virtual void update(float deltaTime);
  virtual void draw(sf::RenderWindow &window);

private:

};

#endif
