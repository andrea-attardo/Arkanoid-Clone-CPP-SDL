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

void Actor::update(const double deltatime) {
	for ( auto i : components ) {
		i->update( deltatime );
	}
}

void Actor::render( SDL_Surface* destsur ) {
	for ( auto i : components ) {
		i->render( destsur );
	}
}

void Actor::addComponent( Component* comp ) {
	components.push_back( comp );
}
