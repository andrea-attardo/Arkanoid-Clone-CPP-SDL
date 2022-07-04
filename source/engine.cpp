#include <iostream>
#include "SDL.h"
#include "engine.h"

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
		 std::cerr << "Error: Class Engine previously istantiated" << std::endl;
		 return NULL;
	 }
 }


/*
void Engine::init() {

	if ( SDL_Init( SDL_INIT_VIDEO ) != 0 ) printf( "Init failed: %s", SDL_GetError() );
	else
	{
		gWindow = SDL_CreateWindow( "SDLGAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH, SCREEN_HEIGTH, SDL_WINDOW_SHOWN );
		if ( gWindow == NULL )printf( "Creating main Window failed\n" );

		gWindowSurface = SDL_GetWindowSurface( gWindow );
	}

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
*/