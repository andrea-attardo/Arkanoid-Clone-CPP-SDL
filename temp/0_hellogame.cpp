//fare l'hellogame fatto in python/pygame in c++/sdl

#include <cstdio>
#include "SDL.h" 


//constants
const int	SCREEN_WIDTH		= 640;
const int	SCREEN_HEIGHT		= 480;
const char* H_WORLD_IMG_PATH	= "asset/helloworld_img.bmp";


//global variables
SDL_Window*		gWindow			= NULL;  // main window
SDL_Surface*	gScreenSurface	= NULL;  // main window's surface
SDL_Surface*	gHelloWorld		= NULL;  // surface to load with HELLO WORD image
bool			gQuit			= false; // flag for usr quit event
SDL_Event		e;						 // general event


//functions declarations
bool init();
bool loadMedia();
void close();
void render();
void processEvents();


//main
int main( int argc, char* argv[] ) { 
	
	init();

	loadMedia();
		
	//game loop
	while ( !gQuit ) {

		processEvents();
				
		//updateGameLogic

		render();
	
	}
		
	close();

	return 0; 
}




//FUNCTIONS DEFINITIONS
// 
//init SDL video subsystem and create a window
bool init() {

	//initialization flag
	bool success = true;

	if ( SDL_Init( SDL_INIT_VIDEO ) != 0 )
	{
		printf("SDL couldn't initialize. SDL_ERROR: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//create a window
		gWindow = SDL_CreateWindow( "PACMAN C++/SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if (gWindow == NULL)
		{
			printf("Window could'nt be created. SDL_Error: %s\n", SDL_GetError());
			success = false;

		}
		else
		{
			//get window's surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return success;
}


//load media
bool loadMedia() {

	bool success = true;

	gHelloWorld = SDL_LoadBMP(H_WORLD_IMG_PATH);
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s. SDL_ERROR: %s", H_WORLD_IMG_PATH, SDL_GetError());
		success = false;
	}
	return success;
}


//free media and shutdown SDL
void close(){

	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}


//apply an image to window surface
void render() {
	SDL_BlitSurface ( gHelloWorld, NULL, gScreenSurface, NULL );
	SDL_UpdateWindowSurface ( gWindow );
}


void processEvents() {
	while ( SDL_PollEvent( &e ) != 0 ) {
		if ( e.type == SDL_QUIT )
		{
			gQuit = true;
		}
	}
}