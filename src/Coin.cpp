// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Coin.cpp

#include "Coin.h"
#include <iostream>

Coin::Coin(): _sprite(), _texture() {

	if (!_texture.loadFromFile("assets/Coin1.png"))
	{
    	std::cout << "Error loading texture." << std::endl;
	}
}

void Coin::draw(std::shared_ptr<sf::RenderWindow> window){
	_sprite.setTexture(_texture);
	_sprite.setScale(1.5f, 1.5f);
	window->draw(_sprite);

}

sf::Vector2f Coin::getPosition(){

	return _sprite.getPosition();

}

void Coin::setPosition(double x, double y){

	_sprite.setPosition(x, y);

}

sf::FloatRect Coin::getGlobalBounds()
{
  return _sprite.getGlobalBounds();
}

bool Coin::collides(std::shared_ptr<Entity> entity)
{
	return getGlobalBounds().intersects(entity->getGlobalBounds());
}

void Coin::update(const float &dt)
{

}

void Coin::handleCollision(Room *room, Entity *entity)
{
	entity->handleCollision(room, this);
}

void Coin::setTexture(GameTextures *manager)
{
	_texture = *manager->getTexture("coin", 21, 20).get();
}
