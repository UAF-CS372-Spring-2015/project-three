// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Room.cpp

#include "Room.h"
#include <memory>

Room::Room(): _shape(), _entities()
{
  initializeShape();
}

void Room::draw(std::shared_ptr<sf::RenderWindow> window, const float dt)
{
  for(auto entity:_entities)
    entity->draw(window, dt);

  window->draw(_shape);
}

sf::Vector2f Room::getPosition()
{
  return _shape.getPosition();
}

sf::Vector2f Room::getCenter()
{
  auto bounds = _shape.getGlobalBounds();
  return sf::Vector2f(bounds.width / 2, bounds.height / 2);
}

void Room::setPosition(double x, double y)
{
  _shape.setPosition(x, y);
}

void Room::setSize(double x, double y)
{
  _shape.setSize(sf::Vector2f(x, y));
  _shape.setOrigin(x/2, y/2);
}

sf::Vector2f Room::getSize()
{
  return _shape.getSize();
}

void Room::initializeShape()
{
  _shape.setOutlineThickness(-_wallThickness);
  _shape.setOutlineColor(sf::Color(255, 255, 255));
  _shape.setFillColor(sf::Color(0,0,0,0));
}

void Room::spawn(std::shared_ptr<Entity> entity, sf::Vector2f location)
{
  entity->setPosition(location.x, location.y);
  _entities.push_back(entity);
}

sf::Vector2f Room::getRandomPosition()
{
  std::random_device rd;
  std::uniform_int_distribution<int> randx(_wallThickness, getSize().x - _wallThickness);
  std::uniform_int_distribution<int> randy(_wallThickness, getSize().y - _wallThickness);

  return sf::Vector2f(randx(rd), randy(rd));
}
