#include "actor.h"


Actor::Actor() {
	x = 0;
	y = 0;
}

void Actor::load() {
	for ( auto i : components ) {
		i->load();
	}
}

void Actor::update() {
	for ( auto i : components ) {
		i->update();
	}
}

void Actor::render( SDL_Surface* destsur, SDL_Rect& destrect ) {
	for ( auto i : components ) {
		i->render( destsur, destrect );
	}
}

void Actor::addComponent( Component* comp ) {
	components.push_back( comp );
}

int Actor::getX() {
	return x;
}

int Actor::getY() {
	return y;
}

void Actor::setX( int xc ) {
	x = xc;
}

void Actor::setY( int yc ) {
	y = yc;
}