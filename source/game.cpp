#include <iostream>
#include <fstream>
#include <cstdio>
#include <chrono>
#include "SDL.h"
#include "json.hpp"
#include "game.h"
#include "scene.h"
#include "actor.h"
#include "component.h"
#include "staticspritecomponent.h"
#include "bouncemovcomponent.h"
#include "pathmovcomponent.h"

using json = nlohmann::json;

const int		SCREEN_WIDTH		= 1024;
const int		SCREEN_HEIGTH		= 768;

//global variables
SDL_Window*		gWindow				= NULL;
SDL_Surface*    gWindowSurface      = NULL;
SDL_Event		gEvent;
bool			gQuit				= false;
Scene			level1;

int main(int argc, char* args[]) {

	init();

	level1.loadSceneFromFile( "game/level1.json" );


	double oldtime = (double)SDL_GetTicks64() / 1000;
	double newtime = 0;
	double deltatime = 0;
	while ( !gQuit ) {
		newtime =  (double)SDL_GetTicks64() / 1000;
		deltatime = newtime - oldtime;
		oldtime = newtime;

		processEvents();

		updateGameLogic( deltatime );

		render();
		
	}

	close();

	return 0;
}




void init() {

	if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) printf( "Init failed: %s", SDL_GetError() );
	else
	{
		gWindow = SDL_CreateWindow( "HELLOGAME SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
								   SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN );
		if ( gWindow == NULL )printf( "Creating main Window failed\n" );

		gWindowSurface = SDL_GetWindowSurface( gWindow );
	}

}


void processEvents() {

	while ( SDL_PollEvent( &gEvent ) ) {
		if ( gEvent.type == SDL_QUIT )
		{
			gQuit = true;
		}
	}
}


void updateGameLogic( const double deltatime ) {

	level1.update( deltatime );
}


void render() {
	if ( SDL_FillRect(gWindowSurface, NULL, SDL_MapRGB( gWindowSurface->format, 0, 0, 0) ) != 0 ) printf( "FillRect failed: %s", SDL_GetError() );

	level1.render( gWindowSurface );

	SDL_UpdateWindowSurface( gWindow );

}


void close() {

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}



