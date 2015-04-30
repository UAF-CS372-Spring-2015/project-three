// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Entity.h

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <memory> // for shared_ptr and make_shared

class Entity {
public:
	virtual ~Entity() = default;
	virtual void draw(std::shared_ptr<sf::RenderWindow>, const float) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual void setPosition(double x, double y) = 0;
private:
};

#endif