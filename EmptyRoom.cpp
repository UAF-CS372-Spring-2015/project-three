#include "EmptyRoom.h"
#include "Coin.h"
#include <memory>
#include <string>
using std::make_shared;
using std::shared_ptr;

EmptyRoom::EmptyRoom(): _shape(), _entities()
{
  initializeShape();
}

void EmptyRoom::generateContent()
{
}

void EmptyRoom::draw(std::shared_ptr<sf::RenderWindow> window, const float dt)
{
  for(auto entity:_entities)
    entity->draw(window, dt);

  window->draw(_shape);
}

sf::Vector2f EmptyRoom::getPosition()
{
  return _shape.getPosition();
}

sf::Vector2f EmptyRoom::getCenter()
{
  auto bounds = _shape.getGlobalBounds();
  return sf::Vector2f(bounds.width / 2, bounds.height / 2);
}

void EmptyRoom::setPosition(double x, double y)
{
  _shape.setPosition(x, y);
}

void EmptyRoom::setSize(double x, double y)
{
  _shape.setSize(sf::Vector2f(x, y));
  _shape.setOrigin(x/2, y/2);
}

void EmptyRoom::initializeShape()
{
  _shape.setOutlineThickness(-20.f);
  _shape.setOutlineColor(sf::Color(255, 255, 255));
  _shape.setFillColor(sf::Color(0,0,0,0));
}

void EmptyRoom::spawn(std::shared_ptr<Entity> entity, sf::Vector2f location)
{
  entity->setPosition(location.x, location.y);
  _entities.push_back(entity);
}
