
#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include <string>
#include "SDL.h"
#include "component.h"
#include "json.hpp"
using json = nlohmann::json;

class Actor {
public:

	Actor( json actDescr );

	void load();

	void update( const double deltatime );

	void render( SDL_Surface* destsur );

	void addComponent( Component* comp );

	std::string getName() { return name; }

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
	std::string name;
	double x;
	double y;
	double w;
	double h;
};

#endif
