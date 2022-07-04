#include <iostream>
#include <string>
#include "SDL.h"
#include "engine.h"
#include "scene.h"

bool Engine::isInstantiated = false;

 Engine::Engine() {
	}

 Engine* Engine::instance()
 {
	 if ( !isInstantiated ) {
		 static Engine* instance = new Engine();
		 isInstantiated = true;
		 return instance;
	 } 
	 else
	 {
		 std::cerr << "Error: class Engine previously istantiated" << std::endl;
		 return NULL;
	 }
 }


void Engine::init(const int windw, const int windh) {

	if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) printf( "Init failed: %s", SDL_GetError() );
	else
	{
		window = SDL_CreateWindow( "SDLGAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
									windw, windh, SDL_WINDOW_SHOWN );
		if ( window == NULL )printf( "Creating main Window failed\n" );

		windowSurface = SDL_GetWindowSurface( window );
	}

}

void Engine::loadScene(std::string filename ) {

	Scene* scene = new Scene;
	scene->sceneFactory( filename );

}


void Engine::gameloop() {

	double oldtime = (double)SDL_GetTicks64() / 1000;
	double newtime = 0;
	double deltatime = 0;
	while ( !gQuit ) {
		newtime = (double)SDL_GetTicks64() / 1000;
		deltatime = newtime - oldtime;
		oldtime = newtime;

		processEvents();

		updateGameLogic( deltatime );

		render();

	

}

void Engine::processEvents() {

	while ( SDL_PollEvent( &gEvent ) ) {
		if ( gEvent.type == SDL_QUIT )
		{
			gQuit = true;
		}
	}
}


void Engine::updateGameLogic( const double deltatime ) {

	level1.update( deltatime );
}


void Engine::render() {
	if ( SDL_FillRect( gWindowSurface, NULL, SDL_MapRGB( gWindowSurface->format, 0, 0, 0 ) ) != 0 ) printf( "FillRect failed: %s", SDL_GetError() );

	level1.render( gWindowSurface );

	SDL_UpdateWindowSurface( gWindow );

}


void Engine::close() {

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}
