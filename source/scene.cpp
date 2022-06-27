#include "scene.h"

Scene::Scene() {}

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

void Scene::render( SDL_Surface* destsur ) {
	for ( auto i : actors ) {
		i->render( destsur );
	}
}

void Scene::addActor( Actor* actor ) {
	actors.push_back( actor );
}