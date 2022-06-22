#include "scene.h"

void Scene::load() {
	for ( auto i : actors ) {
		i->load();
	}
}

void Scene::update() {
	for ( auto i : actors ) {
		i->update();
	}
}

void Scene::render( SDL_Surface* destsur, SDL_Rect& destrect ) {
	for ( auto i : actors ) {
		i->render( destsur, destrect );
	}
}