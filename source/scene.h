#ifndef SCENE_H
#define SCENE_H

#include "SDL.h"
#include <vector>
#include "actor.h"

class Scene {

public:


	void load();

	void update();

	void render( SDL_Surface* destsur, SDL_Rect& destrect );

private:
	std::vector<Actor*> actors;
};

#endif // !SCENE_H
