// CS 372 Project 3
// The Platformer
// Noah Betzen, William Fisher, Jacob McKenna
// Dylan Tucker, William Showalter, Saira Walia, Adam Walters
// Entity.h

#ifndef __ENTITY_H__
#define __ENTITY_H__

class Entity {
public:
	virtual ~Entity() = default;
	virtual void draw() = 0;

private:


}; 

#endif // __ENTITY_H__