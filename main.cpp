// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// main.cpp
// Testing commit

#include <SFML/Graphics.hpp>
#include <memory>
using std::make_shared;

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
                game.exit();
                break;
              case sf::Event::KeyPressed:
                auto gameCommand = game.handleGameInput(event);
                gameCommand->execute(game);

                break;
            }
        }

        game.window()->clear();
        game.window()->draw(shape);
        game.window()->display();
    }

    return 0;
}
