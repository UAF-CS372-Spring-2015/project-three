// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// main.cpp
// Testing commit

#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    Game game;
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (game.window()->isOpen())
    {
        sf::Event event;
        while (game.window()->pollEvent(event))
        {
            switch (event.type)
            {
              case sf::Event::Closed:
                game.window()->close();
                break;
              case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                  game.window()->close();

                break;
            }
        }

        game.window()->clear();
        game.window()->draw(shape);
        game.window()->display();
    }

    return 0;
}
