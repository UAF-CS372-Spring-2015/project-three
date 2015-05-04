// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Menu.cpp

#include "Menu.h"
#include "Game.h"
#include <memory> // for shared_ptr and make_shared
#include <string>
#include <iostream> // for testing with cout, endl
#include <SFML/Graphics.hpp>

Menu::Menu(Game *game):_game(game)
{
  float middleX = _game->window()->getSize().x;
  float middleY = _game->window()->getSize().y;

  Button play("assets/play.png", sf::Vector2f(middleX/2,middleY/6));
  play.callBack = [](){ std::cout << "Play game!" << std::endl; };
  _buttons.push_back(play);
  
  Button quit("assets/quit.png", sf::Vector2f(middleX/2,middleY/3));
  quit.callBack = [](){ std::cout << "Quit game!" << std::endl; exit(0);};
  _buttons.push_back(quit);
}

void Menu::handleInput()
{
  sf::Event input;
  _game->window()->pollEvent(input);

  auto mousePosition = sf::Mouse::getPosition(*_game->window().get());

  if (input.type == sf::Event::MouseButtonReleased)
  {
    for(auto button : _buttons)
    {
      if(button.getBounds().contains(mousePosition.x, mousePosition.y))
      {
        button.callBack();
      }
    }
  }
}

void Menu::update(float deltaTime)
{

}

void Menu::draw(float deltaTime)
{
  _game->window()->clear(sf::Color::Color(0,0,0));

  for(auto button : _buttons)
  {
    button.draw(_game->window());
  }

  _game->window()->display();
}