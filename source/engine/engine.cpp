#include <iostream>
#include "engine.h"
#include "scenefactory.h"

bool Engine::isInstantiated = false;
Engine* Engine::pEngine		= NULL;

 Engine::Engine() {
 
	 window			= NULL;
	 windowSurface	= NULL;
	 scene			= NULL;

	 inputsys		= InputSystem();
	 Event			= {};
	 quit			= false;

	 oldtime		= (double)SDL_GetTicks64() / 1000;
	 newtime		= 0;
	 deltatime		= 0;

 }

 Engine* Engine::instance() {


	 if ( !isInstantiated ) {
		 static Engine* instance = new Engine();
		 pEngine = instance;
		 isInstantiated = true;
	 }

	 return pEngine;

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

	SceneFactory sfactory;
	scene = sfactory.makeScene( filename );
	scene->load();

}


void Engine::gameloop() {

	while ( !quit ) {

		processEvents();
		update();
		render();

	}

}


void Engine::processEvents() {

	while ( SDL_PollEvent( &Event ) ) {
		if ( Event.type == SDL_QUIT )
		{
			quit = true;
		}
		
	}
	
	inputsys.process();

}


void Engine::update() {

	newtime = (double)SDL_GetTicks64() / 1000;

	deltatime = std::min(newtime - oldtime, ( 1.0 / 60.0 ) );
	scene->update( deltatime );

	oldtime = newtime;

}


void Engine::render() {
	if ( SDL_FillRect( windowSurface, NULL, SDL_MapRGB( windowSurface->format, 0, 0, 0 ) ) != 0 ) printf( "FillRect failed: %s", SDL_GetError() );

	scene->render( windowSurface );

	SDL_UpdateWindowSurface( window );

}


void Engine::close() {
	
	/*
	for ( Actor& act : scene ) {

		for ( Component* cmp : act ) {

			delete( cmp );
			cmp = NULL;

		}

		delete( act );
		act = NULL;
		
	}
	*/

	delete( scene );
	scene = NULL;
	

	SDL_Quit();
}
