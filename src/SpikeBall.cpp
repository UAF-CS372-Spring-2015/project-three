// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// SpikeBall.cpp

#include <iostream>
#include "SpikeBall.h"


SpikeBall::SpikeBall()
{
    if (!_texture.loadFromFile("assets/spikeball.png"))
	{
    std::cout << "Error loading texture" << std::endl;
	}

	_sprite.setTexture(_texture);
	_sprite.setOrigin(sf::Vector2f(10.0f, 10.0f));
	_sprite.setScale(sf::Vector2f(.5f, .5f));
}


void SpikeBall::draw(std::shared_ptr<sf::RenderWindow> window, float dt){

	window->draw(_sprite);

}

sf::Vector2f SpikeBall::getPosition(){

	return _sprite.getPosition();

}

void SpikeBall::setPosition(double x, double y){

	_sprite.setPosition(x, y);

}
