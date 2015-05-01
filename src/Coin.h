// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Coin.h

#ifndef COIN_H
#define COIN_H

#include "Entity.h"
#include <memory>

class Coin : public Entity {
public:

	Coin();
	~Coin() throw() {}
	virtual void draw(std::shared_ptr<sf::RenderWindow>, float) override;
	virtual sf::Vector2f getPosition() override;
	virtual void setPosition(double, double) override;

private:
	sf::Sprite _sprite;
	sf::Texture _texture;

};

#endif
