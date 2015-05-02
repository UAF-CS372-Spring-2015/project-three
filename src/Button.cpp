// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Button.cpp

#include "Button.h"
#include <SFML/Graphics.hpp>
#include <string>

Button::Button(const std::string &imageName, sf::Vector2f position):_position(position)
{
  _texture.loadFromFile(imageName);
  _sprite.setTexture(_texture);
  _sprite.setPosition(_position);
}

void Button::draw(std::shared_ptr<sf::RenderWindow> window)
{
  window->draw(_sprite);
}

sf::Vector2u Button::getSize()
{
  return _texture.getSize();
}

sf::FloatRect Button::getBounds()
{
  return _sprite.getGlobalBounds();
}

sf::Vector2f Button::getPosition()
{
  return _sprite.getPosition();
}

void Button::setPosition(sf::Vector2f position)
{
  _sprite.setPosition(position);
}

void Button::setPosition(float x, float y)
{
  _sprite.setPosition(x, y);
}