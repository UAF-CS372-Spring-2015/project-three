// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Button.h

#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class Game;

class Button
{
public:
  ~Button() = default;
  Button() = default;
  Button(const std::string &imageName, sf::Vector2f position = sf::Vector2f(0,0));

  void draw(std::shared_ptr<sf::RenderWindow> window);

  sf::FloatRect getBounds();
  sf::Vector2u getSize();
  sf::Vector2f getPosition();

  void setPosition(sf::Vector2f position);
  void setPosition(float x, float y);

  void (*callBack)(Game *game); // thing to do if button is clicked

private:
  sf::Vector2f _position;
  sf::Texture _texture;
  sf::Sprite _sprite;

};

#endif