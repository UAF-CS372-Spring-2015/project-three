// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Room.cpp

#include "Room.h"
#include "Entity.h"
#include <memory>
#include <iostream>

Room::Room(): _walls(), _background(), _entities()
{
}

void Room::draw(std::shared_ptr<sf::RenderWindow> window)
{
  window->draw(_background);

  for(auto entity:_entities)
    entity->draw(window);

  window->draw(_walls);
}

sf::Vector2f Room::getPosition()
{
  return _walls.getPosition();
}

sf::Vector2f Room::getCenter()
{
  auto bounds = _walls.getGlobalBounds();
  return sf::Vector2f(bounds.width / 2, bounds.height / 2);
}

void Room::setPosition(double x, double y)
{
  _walls.setPosition(x, y);
  _background.setPosition(x, y);
}

void Room::setSize(double width, double height)
{
  _walls.setSize(sf::Vector2f(width, height));
  _background.setSize(sf::Vector2f(width, height));
  // _walls.setOrigin(x/2, y/2);
}

sf::Vector2f Room::getSize()
{
  return _walls.getSize();
}

void Room::initializeShape()
{
  _walls.setOutlineThickness(-_wallThickness);
  _walls.setOutlineColor(sf::Color(255, 255, 255));
  _walls.setFillColor(sf::Color(0,0,0,0.0));
  // _background.setFillColor(sf::Color(38,83,38,255));

  if (!_texture.loadFromFile("assets/grass.png"))
	{
    	std::cout << "Error loading texture" << std::endl;
	}
  _texture.setRepeated(true);
  _background.setTexture(&_texture);
  _background.setTextureRect(sf::IntRect(0,0,getSize().x,getSize().y));
}

bool Room::spawn(std::shared_ptr<Entity> entity, sf::Vector2f location)
{
  auto collided = false;

  entity->setPosition(location.x, location.y);

  collided = collides(entity);

  for(auto spawned_entity:_entities)
    if (spawned_entity->collides(entity))
      collided = true;

  if (!collided)
    _entities.push_back(entity);

  return !collided;
}

void Room::despawn(std::shared_ptr<Entity> entity)
{
  _entities.erase( std::remove( _entities.begin(), _entities.end(), entity ), _entities.end() );
}

void Room::despawn(Entity *entity)
{
  for(auto e:_entities)
    if (e.get() == entity)
      return despawn(e);
}

sf::Vector2f Room::getRandomPosition()
{
  std::random_device rd;
  std::uniform_int_distribution<int> randx(_wallThickness, getSize().x-_wallThickness);
  std::uniform_int_distribution<int> randy(_wallThickness, getSize().y-_wallThickness);

  return sf::Vector2f(randx(rd), randy(rd));
}

sf::FloatRect Room::getGlobalBounds()
{
  return _walls.getGlobalBounds();
}

bool Room::collides(std::shared_ptr<Entity> entity)
{
  auto bounds = entity->getGlobalBounds();
  auto currentBounds = getGlobalBounds();
  auto contains = currentBounds.contains(bounds.left-_wallThickness, bounds.top-_wallThickness);
  contains = contains && currentBounds.contains(bounds.left + bounds.width + _wallThickness, bounds.top + bounds.height + _wallThickness);

  return !contains;
}

void Room::update(const float &dt)
{
  for(auto entity:_entities)
    entity->update(dt);

  checkForCollisions();
}

void Room::checkForCollisions()
{
  using collision_pair = std::pair<std::weak_ptr<Entity>, std::weak_ptr<Entity>>;
  std::vector<collision_pair> collisions;

  for(auto entity:_entities)
  {
    //check for collision with room
    if (collides(entity))
      entity->handleCollision(this);

    //create a list of things that had collisions and handle them at the end
    //using weak pointers incase one of the items should be deleted as part of
    //the collision (user picks up a coin)
    for(auto other_entity:_entities)
      if(entity != other_entity && entity->collides(other_entity))
        collisions.push_back(collision_pair(std::weak_ptr<Entity>(entity), std::weak_ptr<Entity>(other_entity)));
  }

  for(auto cpair:collisions)
  {
    notifyOfCollision(cpair.first, cpair.second);
    notifyOfCollision(cpair.second, cpair.first);
  }
}

void Room::notifyOfCollision(std::weak_ptr<Entity> entity1, std::weak_ptr<Entity> entity2)
{
  auto first = entity1.lock();
  auto second = entity2.lock();

  if (first && second)
    first->handleCollision(this, second.get());
}
