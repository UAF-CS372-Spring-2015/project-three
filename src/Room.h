// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Room.h

#ifndef ROOM_H
#define ROOM_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>
#include <random>

// class Entity;
#include "Entity.h"

class Room
{
public:
  Room();

  //Need to implement for room
  virtual void generateContent() = 0;

  //Implement entity methods
  void draw(std::shared_ptr<sf::RenderWindow>);
	sf::Vector2f getPosition();
	void setPosition(double, double);
  // virtual sf::FloatRect getGlobalBounds() override;
  void update(const float &dt);
  //
  // virtual bool collides(std::shared_ptr<Entity>) override;

  void notifyOfCollision(std::weak_ptr<Entity>, std::weak_ptr<Entity>);
  void checkForCollisions();

  void setSize(double, double);
  sf::Vector2f getSize();
  sf::Vector2f getCenter();
  bool spawn(std::shared_ptr<Entity>, sf::Vector2f);
  void despawn(std::shared_ptr<Entity>);
  void despawn(Entity *);

  void initializeShape();

protected:
  sf::Vector2f getRandomPosition();

private:
  sf::RectangleShape _walls;
  sf::RectangleShape _background;
  sf::Texture _texture;

  std::vector<std::shared_ptr<Entity>> _entities;
  double _wallThickness = 20;
  sf::Vector2f _size;

};

#endif
