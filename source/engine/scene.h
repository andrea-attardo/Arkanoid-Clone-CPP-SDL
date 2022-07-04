#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "SDL.h"
#include "actor.h"

class Scene {

public:

	Scene();

	void load();

	void update( const double deltatime);

	void render( SDL_Surface* destsur );

	void addActor( Actor actor );


private:
	std::vector<Actor> actors;
};

#endif // !SCENE_H
