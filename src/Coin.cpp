// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Coin.cpp

#include "Coin.h"
#include <memory>
#include <iostream>

Coin::Coin(): _sprite(), _texture() {

	if (!_texture.loadFromFile("assets/Coin1.png"))
	{
    std::cout << "Error loading texture" << std::endl;
	}
	// _texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setOrigin(sf::Vector2f(7.5f, 7.5f));
	_sprite.setScale(sf::Vector2f(1.5f, 1.5f));
	_sprite.setPosition(400,400);
}

void Coin::draw(std::shared_ptr<sf::RenderWindow> window, float dt){

	window->draw(_sprite);

}

sf::Vector2f Coin::getPosition(){

	return _sprite.getPosition();

}

void Coin::setPosition(double x, double y){

	_sprite.setPosition(x, y);

}

sf::FloatRect Coin::getBoundingBox() const{

	return _sprite.getGlobalBounds();

}