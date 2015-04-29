#include "Room.h"
#include "Coin.h"
#include <memory>
#include <string>
using std::make_shared;
using std::shared_ptr;

Room::Room(): _shape(), _entities()
{
  initializeShape();
}

Room::Room(const double width, const double height): _shape(), _entities()
{
  initializeShape();
}

void Room::generateContent()
{
  auto pos = getCenter();
  pos.x -= 100;
  pos.y += 300;
  spawn("coin", pos);
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

void Room::initializeShape()
{
  _shape.setOutlineThickness(-20.f);
  _shape.setOutlineColor(sf::Color(255, 255, 255));
  _shape.setFillColor(sf::Color(0,0,0,0));
}

void Room::spawn(std::shared_ptr<Entity> entity, sf::Vector2f location)
{
  entity->setPosition(location.x, location.y);
  _entities.push_back(entity);
}

void Room::spawn(std::string entity, sf::Vector2f location)
{
  shared_ptr<Entity> item;
  if (entity == "coin")
    item = make_shared<Coin>();

  spawn(item, location);
}
