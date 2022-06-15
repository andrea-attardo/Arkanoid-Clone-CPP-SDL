
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

	void addComponent( Component* comp) {
		components.push_back( comp );
	}

	void load() {
		components[0]->load();
		components[1]->load();
	}

	void update() {
		components[1]->update();
	}

	void render( SDL_Surface* destsur, SDL_Rect& destrect ) {
		components[0]->render(destsur, destrect);
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
