// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Room.h

#ifndef ROOM_H
#define ROOM_H

#include <memory>
#include <vector>
#include <string>
#include <random>

#include "Entity.h"

class Room : public Entity
{
public:
  Room();

  //Need to implement for room
  virtual void generateContent() = 0;

  //Implement entity methods
  virtual void draw(std::shared_ptr<sf::RenderWindow>) override;
	virtual sf::Vector2f getPosition() override;
	virtual void setPosition(double, double) override;
  virtual sf::FloatRect getGlobalBounds() override;
  virtual bool collides(std::shared_ptr<Entity>) override;
  virtual void update(const float &dt) override;

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
