#include <iostream>
#include <cstdio>
#include "SDL.h"
#include "hellosdl.h"


const int		SCREEN_WIDTH		= 1024;
const int		SCREEN_HEIGTH		= 768;
const int		CENT_IMG_WIDTH		= 640;
const int		CENT_IMG_HEIGTH		= 480;


enum keyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};


SDL_Window*		gWindow				= NULL;
SDL_Surface*	gWindowSurface		= NULL;
SDL_Surface*	gBackgroundSurface	= NULL;
SDL_Event		gEvent;
bool			gQuit				= false;
SDL_Surface*	gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
SDL_Surface*	gCurrentSurface		= NULL;
SDL_Rect		gCenteredRect;


int main(int argc, char* args[]) {

	init();
	loadMedia();

	//game loop
	while ( !gQuit ) {

		//process events
		processEvents();

		//update game logic



		//render
		SDL_BlitSurface( gCurrentSurface, NULL, gWindowSurface, &gCenteredRect );
		SDL_UpdateWindowSurface( gWindow );

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
		else
		{
			gWindowSurface		= SDL_GetWindowSurface( gWindow );
			gBackgroundSurface	= loadSurface( "asset/background.bmp" );
			gCurrentSurface		= loadSurface( "asset/hellogame.bmp" );

			gCenteredRect.x		= ( SCREEN_WIDTH - CENT_IMG_WIDTH ) / 2;
			gCenteredRect.y		= ( SCREEN_HEIGTH - CENT_IMG_HEIGTH ) / 2;

			SDL_BlitSurface( gBackgroundSurface, NULL, gWindowSurface, NULL );
			SDL_BlitSurface( gCurrentSurface, NULL, gWindowSurface, &gCenteredRect );
		}

	}

}


bool loadMedia() {
	bool success = true;

	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface( "asset/press_default.bmp" );
	if ( gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL )
	{
		printf( "Loading press_default image failed\n" );
		success = false;
	}

	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface( "asset/press_up.bmp" );
	if ( gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL )
	{
		printf( "Loading press_up image failed\n" );
		success = false;
	}

	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface( "asset/press_down.bmp" );
	if ( gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL )
	{
		printf( "Loading press_down image failed\n" );
		success = false;
	}

	gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface( "asset/press_left.bmp" );
	if ( gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT] == NULL )
	{
		printf( "Loading press_left image failed\n" );
		success = false;
	}

	gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface( "asset/press_right.bmp" );
	if ( gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] == NULL )
	{
		printf( "Loading press_right image failed\n" );
		success = false;
	}
	
	return success;
}


void close() {

	SDL_FreeSurface( gBackgroundSurface );
	gBackgroundSurface = NULL;

	for ( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
	{
		SDL_FreeSurface( gKeyPressSurfaces[i] );
		gKeyPressSurfaces[i] = NULL;
	}

	SDL_FreeSurface( gCurrentSurface );
	gCurrentSurface = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}


void processEvents() {

	while ( SDL_PollEvent( &gEvent ) ) {
		if ( gEvent.type == SDL_QUIT )
		{
			gQuit = true;
		}
		else if ( gEvent.type == SDL_KEYDOWN )
		{
			switch ( gEvent.key.keysym.sym ) 
			{
				case SDLK_UP:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
					break;

				case SDLK_DOWN:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
					break;

				case SDLK_LEFT:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
					break;

				case SDLK_RIGHT:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
					break;

				default:
					gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
					break;
			}

		}
	}
}


SDL_Surface* loadSurface( const char* path ) {

	SDL_Surface* loadedSurface = SDL_LoadBMP( path );
	if ( loadedSurface == NULL ) {
		printf( "LoadingSurface failed\n" );
	}
	return loadedSurface;
}