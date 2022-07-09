#include "scene.h"

Scene::Scene() {}

void Scene::load() {
	for ( Actor* act : actors ) {
		act->load();
	}
}

void Scene::update( const double deltatime) {
	for ( Actor* act : actors ) {
		act->update( deltatime );
	}
}

void Scene::render( SDL_Surface* destsur ) {
	for ( Actor* act : actors ) {
		act->render( destsur );
	}
}

void Scene::addActor( Actor* actor ) {
	actors.push_back( actor );
}

