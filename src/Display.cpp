#include "Display.h"
#include <iostream>
#include <string>

Display::Display():_text(), _font()
{
	setup(0);
}

void Display::draw(std::shared_ptr<sf::RenderWindow> window) {

	window->draw(_text);

}

void Display::setup(unsigned int coins) {

	if (!_font.loadFromFile("assets/Arial.ttf"))
	{
	    std::cout << "Error loading whatever" << std::endl;
	}

	_text.setFont(_font);
 	_text.setPosition(2600,110);
  	_text.setString(std::to_string(coins));
  	_text.setCharacterSize(60);
}