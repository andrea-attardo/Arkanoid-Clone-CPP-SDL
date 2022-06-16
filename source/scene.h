#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "SDL.h"
#include "actor.h"

class Scene {

public:


	void load(){
		for ( auto i : actors ) {
			i->load();
		}
	}

	void update(){
		for ( auto i : actors ) {
			i->update();
		}
	}
	
	void render( SDL_Surface* destsur, SDL_Rect& destrect ) {
		for ( auto i : actors ) {
			i->render( destsur, destrect );
		}
	}

private:
	std::vector<Actor*> actors;
};

#endif // !SCENE_H

