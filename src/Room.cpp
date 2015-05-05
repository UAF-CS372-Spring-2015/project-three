// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Room.cpp

#include "Room.h"
#include "Entity.h"
#include "RoomWall.h"

#include <random>
#include <memory>
#include <iostream>

Room::Room(): _walls(), _background(), _entities(), _size()
{
}

void Room::draw(std::shared_ptr<sf::RenderWindow> window)
{
  window->draw(_background);

  for(auto entity:_entities)
    entity->draw(window);

}

void Room::setSize(double width, double height)
{
  _size.x = width;
  _size.y = height;
  _background.setSize(sf::Vector2f(width, height));
}

sf::Vector2f Room::getSize()
{
  return _size;
}

sf::Vector2f Room::getCenter()
{
  return sf::Vector2f(_size.x/2, _size.y/2);
}

void Room::initializeShape()
{
  auto topWall = std::make_shared<RoomWall>(_size.x-50, 50);
  spawn(topWall, sf::Vector2f(0,0));
  auto rightWall = std::make_shared<RoomWall>(50, _size.y);
  spawn(rightWall, sf::Vector2f(_size.x-50,0));
  auto leftWall = std::make_shared<RoomWall>(50, _size.y);
  spawn(leftWall, sf::Vector2f(0,50));
  auto bottomWall = std::make_shared<RoomWall>(_size.x - 100, 50);
  spawn(bottomWall, sf::Vector2f(50,_size.y-50));

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
