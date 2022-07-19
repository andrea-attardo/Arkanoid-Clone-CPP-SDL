
#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include <string>
#include "SDL.h"
#include "component.h"
#include ".././/mathvec.h"
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

	void setX( double xc ) { x = xc; }
	double getX() const { return x; }

	void setY( double yc ) { y = yc; }
	double getY() { return y; }

	void setW( double wc ) { w = wc; }
	double getW() const { return w; }

	void setH( double hc ) { h = hc; }
	double getH() const { return h; }

	void setV( const Vector2& vec2 ) { v.x = vec2.x; v.y = vec2.y; }

	void setVx( double vx ) { v.x = vx; }
	void setVy( double vy ) { v.y = vy; }

	const Vector2& getV() const { return v; }


private:
	std::vector<Component*> components;
	std::string name;
	double x;
	double y;
	double w;
	double h;
	Vector2 v;
	double speed;

};

#endif
