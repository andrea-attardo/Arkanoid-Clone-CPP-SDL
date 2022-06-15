#include <iostream>
#include <cstdio>
#include "SDL.h"
#include "game.h"
#include "actor.h"
#include "component.h"
#include "staticspritecomponent.h"
#include "bouncemovcomponent.h"


const int		SCREEN_WIDTH		= 1024;
const int		SCREEN_HEIGTH		= 768;


SDL_Window*		gWindow				= NULL;
SDL_Surface*	gWindowSurface		= NULL;
SDL_Rect		gDestRect;
SDL_Event		gEvent;
bool			gQuit				= false;
Actor			ghost1;
Component*		pGhost1Sprite 		= NULL;
Component*		pGhost1Movement		= NULL; 


int main(int argc, char* args[]) {

	init();	

	StaticSpriteComponent ghost1Sprite( "assets/ghost1.bmp", &ghost1 );
	pGhost1Sprite = &ghost1Sprite;

	BounceMovComponent ghost1Movement( gWindowSurface, &ghost1 );
	pGhost1Movement = &ghost1Movement;

	ghost1.addComponent( pGhost1Sprite );
	ghost1.addComponent( pGhost1Movement );
	ghost1.load();


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

	ghost1.update();
}


void render() {
	if ( SDL_FillRect(gWindowSurface, NULL, SDL_MapRGB( gWindowSurface->format, 0, 0, 0) ) != 0 ) printf( "FillRect failed: %s", SDL_GetError() );

	ghost1.render( gWindowSurface, gDestRect );

	SDL_UpdateWindowSurface( gWindow );

	SDL_Delay( 16 );
}


void close() {

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}



