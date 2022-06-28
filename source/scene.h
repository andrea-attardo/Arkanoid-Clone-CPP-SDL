#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SDL.h"
#include "actor.h"
#include "scene.h"
#include "actor.h"
#include "component.h"
#include "staticspritecomponent.h"
#include "bouncemovcomponent.h"
#include "json.hpp"
using json = nlohmann::json;

class Scene {

public:

	Scene();

    //private?
	void load();

	void update();

	void render( SDL_Surface* destsur );

	void addActor( Actor actor );

	void loadSceneFromFile( std::string fileName );

private:
	std::vector<Actor> actors;
    std::ifstream sceneFile;
};

#endif // !SCENE_H
