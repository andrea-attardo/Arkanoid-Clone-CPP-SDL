
#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include <SDL.h>
#include "component.h"


class Actor {
public:

	Actor();

	void load();

	void update();

	void render( SDL_Surface* destsur, SDL_Rect& destrect );

	void addComponent( Component* comp );

	int getX();

	int getY();

	void setX( int xc );

	void setY( int yc );

private:
	std::vector<Component*> components;
	int x;
	int y;

};

#endif
