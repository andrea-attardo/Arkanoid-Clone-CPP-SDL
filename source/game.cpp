#include <iostream>
#include <fstream>
#include <cstdio>
#include <chrono>
#include "SDL.h"
#include "json.hpp"
#include "engine.h"
#include "scene.h"
#include "actor.h"
#include "component.h"
#include "staticspritecomponent.h"
#include "bouncemovcomponent.h"
#include "pathmovcomponent.h"
using json = nlohmann::json;

const int	WINDOW_WIDTH = 1024;
const int	WINDOW_HEIGTH = 768;


int main(int argc, char* args[]) {

	Engine* engine = Engine::instance();

	engine->init( WINDOW_WIDTH, WINDOW_HEIGTH );
	engine->loadScene( "game/level1.json" );

	engine->gameloop();

	engine->close();
	
	return 0;
}








