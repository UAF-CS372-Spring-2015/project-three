// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Player.cpp

#include "Player.h"
#include <iostream>
#include <memory>
using std::shared_ptr;

Player::Player():_lives(3), _shape(100.f)
{
}

unsigned int Player::getLives(){

	return _lives;

}

void Player::draw(shared_ptr<sf::RenderWindow> window) {
	_shape.setFillColor(sf::Color::Green);
	_shape.setPosition(getX(), getY());

	window->draw(_shape);

}
