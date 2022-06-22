#include <iostream>
#include <cstdio>
#include "SDL.h"
#include "game.h"
#include "scene.h"
#include "actor.h"
#include "component.h"
#include "staticspritecomponent.h"
#include "bouncemovcomponent.h"


const int		SCREEN_WIDTH		= 1024;
const int		SCREEN_HEIGTH		= 768;

//global variables
SDL_Window*		gWindow				= NULL;
SDL_Surface*	gWindowSurface		= NULL;
SDL_Rect		gDestRect;
SDL_Event		gEvent;
bool			gQuit				= false;
Scene			level1;


int main(int argc, char* args[]) {

	init();

	//load ghost1
	Actor	ghost1;
	StaticSpriteComponent ghost1Sprite( "assets/ghost1.bmp", &ghost1 );
	BounceMovComponent ghost1Movement( gWindowSurface, &ghost1 );

	ghost1.addComponent( &ghost1Sprite );
	ghost1.addComponent( &ghost1Movement );

	ghost1.load();


	//load ghost2
	Actor	ghost2;
	StaticSpriteComponent ghost2Sprite( "assets/ghost2.bmp", &ghost2 );
	BounceMovComponent ghost2Movement( gWindowSurface, &ghost2 );

	ghost2.addComponent( &ghost2Sprite );
	ghost2.addComponent( &ghost2Movement );

	ghost2.setX( 500 );
	ghost2.setY( 300 );

	ghost2.load();


	//load scene
	level1.addActor( &ghost1 );
	level1.addActor( &ghost2 );

	level1.load();


	//game loop
	while ( !gQuit ) {

		processEvents();

		updateGameLogic();

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


void updateGameLogic() {

	level1.update();
}


void render() {
	if ( SDL_FillRect(gWindowSurface, NULL, SDL_MapRGB( gWindowSurface->format, 0, 0, 0) ) != 0 ) printf( "FillRect failed: %s", SDL_GetError() );

	level1.render( gWindowSurface, gDestRect );

	SDL_UpdateWindowSurface( gWindow );

	SDL_Delay( 16 );
}


void close() {

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}



