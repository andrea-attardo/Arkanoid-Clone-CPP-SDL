
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

	void setName( const std::string name ) { 
		actname = name; 
	}

	std::string getName() { return actname; }

	void setX( const double xc ) { x = xc; }

	double getX() { return x; }

	void setY( const double yc ) { y = yc; }

	double getY() { return y; }

	void setW( const double wc ) { w = wc; }

	double getW() { return w; }

	void setH( const double hc ) { h = hc; }

	double getH() { return h; }


private:
	std::vector<Component*> components;
	std::string actname;
	double x;
	double y;
	double w;
	double h;
};

#endif
