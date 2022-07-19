#include "actor.h"


Actor::Actor(json actDescr) {

	name	= actDescr["name"];
	x		= actDescr["x"];
	y		= actDescr["y"];
	w		= actDescr["w"];
	h		= actDescr["h"];
	v.x		= actDescr["vx"];
	v.y		= actDescr["vy"];
	speed   = 400;

}

void Actor::load() {
	for ( Component* cmp : components ) {
		cmp->load();
	}
}

void Actor::update(const double deltatime) {
	for ( Component* cmp : components ) {
		cmp->update( deltatime );
	}
}

void Actor::render( SDL_Surface* destsur ) {
	for ( Component* cmp : components ) {
		cmp->render( destsur );
	}
}

void Actor::addComponent( Component* comp ) {
	components.push_back( comp );
}
