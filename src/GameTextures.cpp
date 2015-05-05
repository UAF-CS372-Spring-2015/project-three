

#include "GameTextures.h"
#include <iostream>

GameTextures::GameTextures()
{
  if (!_image.loadFromFile("assets/DungeonCrawl_ProjectUtumnoTileset.png"))
	{
    	std::cout << "Error loading texture." << std::endl;
	}
}

std::shared_ptr<sf::Texture> GameTextures::getTexture(std::string name, int x, int y)
{
  std::cout << "Loading " << name << std::endl;
  auto texture = _textures.find(name);
  if (texture == _textures.end())
  {
    _textures[name]=getTexture(x, y);
  }

  return _textures[name];
}

std::shared_ptr<sf::Texture> GameTextures::getTexture(int x, int y)
{
  auto texture = std::make_shared<sf::Texture>();
  texture->loadFromImage(_image, sf::IntRect(x*32, y*32, 32, 32));
  texture->setRepeated(true);
  return texture;
}
