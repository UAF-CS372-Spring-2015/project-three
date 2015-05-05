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
}

void Menu::setup()
{
  float middleX = _game->window()->getSize().x;
  float middleY = _game->window()->getSize().y;

  std::shared_ptr<Button> play = std::make_shared<Button>("assets/play.png", sf::Vector2f(middleX/2,middleY/6));
  play->callBack = [](Game *game){ std::cout << "Play game!" << std::endl; game->pauseGame();};
  _buttons.push_back(play);

  std::shared_ptr<Button> quit = std::make_shared<Button>("assets/quit.png", sf::Vector2f(middleX/2,middleY/3));
  quit->callBack = [](Game *game){ std::cout << "Quit game!" << std::endl; game->exit();};
  _buttons.push_back(quit);

  std::shared_ptr<Button> win = std::make_shared<Button>("assets/You_Win.png", sf::Vector2f(middleX/2,middleY/2));
  quit->callBack = [](Game *game){ std::cout << "Quit game!" << std::endl; game->exit();};
  _buttons.push_back(win);

}

void Menu::handleInput(sf::Event input)
{
  // sf::Event input;
  // _game->window()->pollEvent(input);
  //
  auto mousePosition = sf::Mouse::getPosition(*_game->window().get());

  if (input.type == sf::Event::MouseButtonReleased)
  {
    for(auto button : _buttons)
    {
      if(button->getBounds().contains(mousePosition.x, mousePosition.y))
      {
        button->callBack(_game);
      }
    }
  }
}

void Menu::update(float deltaTime)
{

}

void Menu::draw(float deltaTime)
{
  _game->window()->clear(sf::Color::Color(128,128,128));

  for(auto button : _buttons)
  {
    button->draw(_game->window());
  }

  _game->window()->display();
}

void Menu::gameOver() {

  _game->window()->clear(sf::Color::Color(128,128,128));

  _buttons[2]->draw(_game->window());

  _game->window()->display();
  
}



