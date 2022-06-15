#include <iostream>
#include <cstdio>
#include "SDL.h"
#include "bouncing.h"


const int		SCREEN_WIDTH		= 1024;
const int		SCREEN_HEIGTH		= 768;


SDL_Window*		gWindow				= NULL;
SDL_Surface*	gWindowSurface		= NULL;
SDL_Event		gEvent;
bool			gQuit				= false;
SDL_Surface*	gBall				= NULL;
SDL_Rect		gBallRect;

double			gBall_x				= 0.0;
double			gBall_y				= 0.0;
double			gBall_vx			= 5.0;
double			gBall_vy			= 5.0;


int main(int argc, char* args[]) {

	init();
	loadMedia();

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


bool loadMedia() {
	bool success = true;

	gBall = SDL_LoadBMP( "assets/palla.bmp" );
	if ( gBall == NULL )
	{
		printf( "Loading assets/palla.bmp image failed\n" );
		success = false;
	}

	return success;
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
	
	//Ball's bouncing logic
	gBall_x += gBall_vx;
	gBall_y += gBall_vy;
	
	if ( gBall_x < 0 || (gBall_x + gBall->w)  >= gWindowSurface->w )
	{
		gBall_vx = -gBall_vx;
	}
	
	if ( gBall_y < 0 || ( gBall_y + gBall->h ) >= gWindowSurface->h )
	{
		gBall_vy = -gBall_vy;
	}
	
}


void render() {
	if ( SDL_FillRect(gWindowSurface, NULL, SDL_MapRGB( gWindowSurface->format, 0, 0, 0) ) != 0 ) printf( "FillRect failed: %s", SDL_GetError() );

	gBallRect.w		= gBall->w;
	gBallRect.h		= gBall->h;
	gBallRect.x		= gBall_x;
	gBallRect.y		= gBall_y;

	SDL_BlitSurface( gBall, NULL, gWindowSurface, &gBallRect );
	SDL_UpdateWindowSurface( gWindow );

	SDL_Delay( 16 );
}


void close() {

	SDL_FreeSurface( gBall );
	gBall = NULL;

	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	SDL_Quit();
}



