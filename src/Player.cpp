// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Player.cpp

#include "Player.h"
#include <iostream> // for cout and endl
#include <memory> // for shared_ptr and make_shared

Player::Player():_lives(3), _sprite(), _texture(),_facing(PLAYER_FACE_RIGHT), _currentSpeed(0.f,0.f), _moveSpeed(500.f)
{
	if (!_texture.loadFromFile("assets/mini_morphea_sprite_sheet_by_nyaneoneko-d5brzm5.png"))
	{
    	std::cout << "Error loading texture" << std::endl;
	}
	// _texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setOrigin(sf::Vector2f(16, 16));
	_sprite.setScale(sf::Vector2f(4.f, 4.f));
}

unsigned int Player::getLives(){

	return _lives;

}

void Player::draw(std::shared_ptr<sf::RenderWindow> window, const float dt) {
	_sprite.setTextureRect(_facing);
	updatePosition(dt);
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

bool Player::isFacingUp()
{
	return isFacing(PLAYER_FACE_UP);
}

bool Player::isFacingDown()
{
	return isFacing(PLAYER_FACE_DOWN);
}

bool Player::isFacingLeft()
{
	return isFacing(PLAYER_FACE_LEFT);
}

bool Player::isFacingRight()
{
	return isFacing(PLAYER_FACE_RIGHT);
}

bool Player::isFacing(sf::IntRect dir)
{
	return _facing == dir;
}

sf::Vector2f Player::getPosition()
{
	return _sprite.getPosition();
}

void Player::setPosition(double x, double y)
{
	_sprite.setPosition(x, y);
}

sf::Vector2f Player::getCurrentSpeed()
{
	return _currentSpeed;
}

void Player::setCurrentSpeed(double x, double y)
{
	_currentSpeed.x = x;
	_currentSpeed.y = y;
}

void Player::updatePosition(const float dt)
{
	auto pos = getPosition();

	pos.x += getCurrentSpeed().x * dt;
	pos.y += getCurrentSpeed().y * dt;

	setPosition(pos.x, pos.y);
}
float Player::getMoveSpeed()
{
    return _moveSpeed;
}
void Player::setMoveSpeed(double moveSpeed)
{
    _moveSpeed = moveSpeed;
}
