#include "Game.h"
#include <memory>
using std::shared_ptr;
using std::make_shared;

Game::Game(): _window(make_shared<sf::RenderWindow>(sf::VideoMode(500,500), "The Platformer"))
{

}

shared_ptr<sf::RenderWindow> Game::window()
{
  return _window;
}
