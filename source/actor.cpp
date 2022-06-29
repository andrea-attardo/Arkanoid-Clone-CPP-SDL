#include "actor.h"


Actor::Actor(json actDescr) {
	name = actDescr["name"];
	x = actDescr["x"];
	y = actDescr["y"];
	w = actDescr["w"];
	h = actDescr["h"];
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
