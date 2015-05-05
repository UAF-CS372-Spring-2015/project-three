#ifndef __THEPLATFORMER_GAME_TEXTURES_H__
#define __THEPLATFORMER_GAME_TEXTURES_H__

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>

class GameTextures
{
public:
  GameTextures();
  ~GameTextures() = default;

  std::shared_ptr<sf::Texture> getTexture(std::string, int x, int y);
  std::shared_ptr<sf::Texture> getTexture(int x, int y);
private:
  sf::Image _image;
  std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
};

#endif
