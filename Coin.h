// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Coin.h

#ifndef __COIN_H__
#define __COIN_H__ 

#include "Entity.h"
#include <memory>
#define COIN_FACE sf::IntRect(0, 97, 31, 31)

class Coin : public Entity {
public:

	Coin();
	virtual void draw(std::shared_ptr<sf::RenderWindow>) override;
	virtual sf::Vector2f getPosition() override;
	virtual void setPosition(double, double) override;

private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::IntRect _facing;

};



#endif // __COIN_H__


