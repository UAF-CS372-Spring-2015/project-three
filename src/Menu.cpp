// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Menu.cpp

#include "Menu.h"

#include <memory> // for shared_ptr and make_shared
#include <string>
#include <iostream> // for testing with cout, endl
#include <SFML/Graphics.hpp>

Menu::Menu()
{
  float middleX = window()->getSize().x;
  float middleY = window()->getSize().y;

  Button play("assets/play.png", sf::Vector2f(middleX/2,middleY/6));
  play.callBack = [](){ std::cout << "Play game!" << std::endl; };
  _buttons.push_back(play);
  
  Button quit("assets/quit.png", sf::Vector2f(middleX/2,middleY/3));
  quit.callBack = [](){ std::cout << "Quit game!" << std::endl; };
  _buttons.push_back(quit);
}

void Menu::handleInput()
{
  //sf::Event input;

  if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    for(auto button : _buttons)
    {
      if(button.getBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window().get()))))
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

}