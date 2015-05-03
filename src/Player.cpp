// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Player.cpp

#include "Player.h"
#include "Room.h"
#include "Coin.h"

#include <iostream> // for cout and endl
#include <memory> // for shared_ptr and make_shared

Player::Player():_lives(3), _facing(PLAYER_FACE_RIGHT), _sprite(), _texture(), _speed(0.f,0.f), _previousPosition()
{
	if (!_texture.loadFromFile("assets/mini_morphea_sprite_sheet_by_nyaneoneko-d5brzm5.png"))
	{
    	std::cout << "Error loading texture" << std::endl;
	}
	// _texture.setSmooth(true);
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(_facing);
	// _sprite.setOrigin(sf::Vector2f(16, 16));
	_sprite.setScale(sf::Vector2f(4.f, 4.f));
}

unsigned int Player::getLives(){

	return _lives;

}

void Player::draw(std::shared_ptr<sf::RenderWindow> window) {
	_sprite.setTextureRect(_facing);
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
	_previousPosition = getPosition();
	_sprite.setPosition(x, y);
}

sf::Vector2f Player::getSpeed()
{
	return _speed;
}

void Player::setSpeed(double x, double y)
{
	_speed.x = x;
	_speed.y = y;
}

void Player::update(const float &dt)
{
	auto pos = getPosition();

	pos.x += getSpeed().x * dt;
	pos.y += getSpeed().y * dt;

	setPosition(pos.x, pos.y);
}

sf::FloatRect Player::getGlobalBounds()
{
	std::cout << getPosition().x << " x " << getPosition().y << std::endl;
	std::cout << _sprite.getGlobalBounds().width << " x " << _sprite.getGlobalBounds().height << std::endl;
	return _sprite.getGlobalBounds();
}

bool Player::collides(std::shared_ptr<Entity> entity)
{
	return getGlobalBounds().intersects(entity->getGlobalBounds());
}

void Player::handleCollision(Room *room)
{
	setPosition(_previousPosition.x, _previousPosition.y);
	setSpeed(0,0);
}
