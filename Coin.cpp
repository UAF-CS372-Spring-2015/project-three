// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Coin.cpp

#include "Coin.h"
#include <memory>

Coin::Coin(): _sprite(), _texture(), _facing(COIN_FACE) {

	if (!_texture.loadFromFile("assets/mini_morphea_sprite_sheet_by_nyaneoneko-d5brzm5.png"))
	{
    std::cout << "Error loading texture" << std::endl;
	}

	_sprite.setTexture(_texture);
	_sprite.setOrigin(sf::Vector2f(16, 16));
	_sprite.setScale(sf::Vector2f(4.f, 4.f));
	//_sprite.setPosition(sf::Vector2f(400, 300));

}

void Coin::draw(std::shared_ptr<sf::RenderWindow>){

	_sprite.setTextureRect(_facing);
	updatePosition();
	window->draw(_sprite);

}

sf::Vector2f Coin::getPosition(){

	return _sprite.getPosition();

}

void Coin::setPosition(double x, double y){

	_sprite.setPosition(x, y);

}
