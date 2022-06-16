
#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include <SDL.h>
#include "component.h"


class Actor {
public:

	Actor() {
		x = 0;
		y = 0;
	}

	void load() {
		for ( auto i : components ) {
			i->load();
		}
	}

	void update() {
		for ( auto i : components ) {
			i->update();
		}
	}

	void render( SDL_Surface* destsur, SDL_Rect& destrect ) {
		for ( auto i : components ) {
			i->render( destsur, destrect );
		}
	}

	void addComponent( Component* comp ) {
		components.push_back( comp );
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	void setX( int xc) {
		x = xc;
	}

	void setY( int yc ) {
		y = yc;
	}

private:
	std::vector<Component*> components;
	int x;
	int y;

};

#endif
