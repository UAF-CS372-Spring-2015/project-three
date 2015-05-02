// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// SpikeBall.cpp

#include <iostream>
#include "SpikeBall.h"


SpikeBall::SpikeBall(): _sprite(), _texture()
{
    if (!_texture.loadFromFile("assets/spikeball.png"))
	{
    std::cout << "Error loading texture" << std::endl;
	}

	_sprite.setTexture(_texture);
	_sprite.setOrigin(sf::Vector2f(10.0f, 10.0f));
	_sprite.setScale(sf::Vector2f(.08f, .08f));
}


void SpikeBall::draw(std::shared_ptr<sf::RenderWindow> window, float dt)
{
	updatePosition(dt);
	window->draw(_sprite);

}

sf::Vector2f SpikeBall::getPosition()
{

	return _sprite.getPosition();

}

void SpikeBall::setPosition(double x, double y)
{

	_sprite.setPosition(x, y);
}

sf::Vector2f SpikeBall::getCurrentSpeed()
{
	return _currentSpeed;
}

void SpikeBall::setCurrentSpeed(double x, double y)
{
	_currentSpeed.x = x;
	_currentSpeed.y = y;
}

void SpikeBall::updatePosition(const float dt)
{
	auto pos = getPosition();

	pos.x += getCurrentSpeed().x * dt;
	pos.y += getCurrentSpeed().y * dt;

	setPosition(pos.x, pos.y);
}
float SpikeBall::getMoveSpeed()
{
    return _moveSpeed;
}
void SpikeBall::setMoveSpeed(double moveSpeed)
{
    _moveSpeed = moveSpeed;
}
