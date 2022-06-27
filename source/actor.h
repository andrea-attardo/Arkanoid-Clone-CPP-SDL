
#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include <string>
#include "SDL.h"
#include "component.h"


class Actor {
public:

	Actor();

	void load();

	void update();

	void render( SDL_Surface* destsur );

	void addComponent( Component* comp );

	void setName( const std::string name );

	int getX() { return x; }

	int getY() { return y; }

	void setX( const int xc ) { x = xc; }

	void setY( const int yc ) { y = yc; }


private:
	std::vector<Component*> components;
	std::string actname;
	int x;
	int y;
};

#endif
