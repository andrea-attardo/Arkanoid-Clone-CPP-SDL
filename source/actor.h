
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

	void update( const double deltatime );

	void render( SDL_Surface* destsur );

	void addComponent( Component* comp );

	void setName( const std::string name );

	double getX() { return x; }

	double getY() { return y; }

	void setX( const double xc ) { x = xc; }

	void setY( const double yc ) { y = yc; }


private:
	std::vector<Component*> components;
	std::string actname;
	double x;
	double y;
};

#endif
