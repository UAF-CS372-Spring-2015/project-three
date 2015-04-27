// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Entity.h

#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <SFML/Graphics.hpp>
#include <memory>

class Entity {
public:
	virtual ~Entity() = default;
	virtual void draw(std::shared_ptr<sf::RenderWindow>) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual void setPosition(double, double) = 0;
private:
};

#endif // __ENTITY_H__
