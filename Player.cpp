// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Player.cpp

#include "Player.h"
#include <iostream>
#include <memory>
using std::shared_ptr;

Player::Player():_lives(3), _facing(PLAYER_FACE_RIGHT), _sprite(), _texture()
{
	if (!_texture.loadFromFile("assets/mini_morphea_sprite_sheet_by_nyaneoneko-d5brzm5.png"))
	{
    std::cout << "Error loading texture" << std::endl;
	}
	// _texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setOrigin(sf::Vector2f(16, 16));
}

unsigned int Player::getLives(){

	return _lives;

}

void Player::draw(shared_ptr<sf::RenderWindow> window) {
	_sprite.setTextureRect(_facing);
	_sprite.setPosition(getX(), getY());
	_sprite.setScale(sf::Vector2f(4.f, 4.f));
	window->draw(_sprite);

}

void Player::faceLeft()
{
	_facing = PLAYER_FACE_LEFT;
}

void Player::faceRight()
{
	_facing = PLAYER_FACE_RIGHT;
}

void Player::faceUp()
{
	_facing = PLAYER_FACE_UP;
}

void Player::faceDown()
{
	_facing = PLAYER_FACE_DOWN;
}
