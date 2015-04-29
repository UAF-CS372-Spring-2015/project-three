#include "Room.h"
#include <memory>
using std::make_shared;
using std::shared_ptr;

Room::Room(): _shape()
{
  initializeShape();
}

Room::Room(const double width, const double height): _shape()
{
  initializeShape();
}

void Room::draw(std::shared_ptr<sf::RenderWindow> window, const float dt)
{
  window->draw(_shape);
}

sf::Vector2f Room::getPosition()
{
  return _shape.getPosition();
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

void Room::initializeShape()
{
  _shape.setOutlineThickness(10.f);
  _shape.setOutlineColor(sf::Color(255, 255, 255));
  _shape.setFillColor(sf::Color(0,0,0,0));
}
