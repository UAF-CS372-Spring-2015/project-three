#include "RoomWall.h"

RoomWall::RoomWall(): _walls()
{
  initializeShape();
}

RoomWall::RoomWall(double width, double height): _walls(sf::Vector2f(width, height))
{
  initializeShape();
}

void RoomWall::initializeShape()
{
  // _walls.setOutlineColor(sf::Color(255, 255, 255));
  // _walls.setFillColor(sf::Color(255, 255, 255));
}

void RoomWall::draw(std::shared_ptr<sf::RenderWindow> window)
{
  _walls.setTexture(_texture.get());
  _walls.setTextureRect(sf::IntRect(0, 0, getSize().x, getSize().y));
  window->draw(_walls);
}

sf::Vector2f RoomWall::getPosition()
{
  return _walls.getPosition();
}

void RoomWall::setPosition(double x, double y)
{
  _walls.setPosition(x, y);
}

void RoomWall::update(const float &dt)
{
}

bool RoomWall::collides(std::shared_ptr<Entity> entity)
{
  return getGlobalBounds().intersects(entity->getGlobalBounds());
}

void RoomWall::setSize(double width, double height)
{
  _walls.setSize(sf::Vector2f(width, height));
}

sf::Vector2f RoomWall::getSize()
{
  return _walls.getSize();
}

sf::FloatRect RoomWall::getGlobalBounds()
{
  return _walls.getGlobalBounds();
}

void RoomWall::handleCollision(Room *room, Entity *entity)
{
	entity->handleCollision(room, this);
}

void RoomWall::setTexture(GameTextures *manager)
{
  _texture = manager->getTexture("wall", 9, 16);
}
