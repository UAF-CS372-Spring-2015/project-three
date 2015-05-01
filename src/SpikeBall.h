// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// SpikeBall.h


#ifndef SPIKEBALL_H
#define SPIKEBALL_H

#include "Entity.h"


class SpikeBall : public Entity
{
public:
    SpikeBall();
    ~SpikeBall() throw() {}
    virtual void draw(std::shared_ptr<sf::RenderWindow>, float) override;
    virtual sf::Vector2f getPosition() override;
    virtual void setPosition(double, double) override;
protected:
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
};

#endif // SPIKEBALL_H
