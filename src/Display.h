#ifndef DISPLAY_H
#define DISPLAY_H

#include <memory>
#include <SFML/Graphics.hpp>

class Display {
public:

	Display();
	void draw(std::shared_ptr<sf::RenderWindow> window);
	void updateInfo();
	void setup(unsigned int);


private:
	sf::Text _text;
  	sf::Font _font;

};

#endif // DISPLAY_H