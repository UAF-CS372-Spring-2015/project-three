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

class Entity;

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
  sf::FloatRect getGlobalBounds();
  bool collides(std::shared_ptr<Entity>);
  void update(const float &dt);
  // virtual void collisionNotify(Entity *) override;

  void setSize(double, double);
  sf::Vector2f getSize();
  sf::Vector2f getCenter();
  void spawn(std::shared_ptr<Entity>, sf::Vector2f);

  void initializeShape();

protected:
  sf::Vector2f getRandomPosition();

private:
  sf::RectangleShape _shape;
  std::vector<std::shared_ptr<Entity>> _entities;
  double _wallThickness = 20;

};

#endif
