#include <cstdio>
#include "SDL.h"
#include "staticspritecomponent.h"


	StatiSpriteComponent::StatiSpriteComponent() {
		image			= NULL;
		x				= 0.0;
		y				= 0.0;
		vx				= 5.0;
		vy				= 5.0;
	}


	void StatiSpriteComponent::load( const char* imgpath ) {
		image = SDL_LoadBMP( imgpath );
		if ( image == NULL ) {
			printf( "Loading image %s failed\n", imgpath );
		}
	}


	 void StatiSpriteComponent::render( SDL_Surface* destsur, SDL_Rect &destrect ) {
		if ( image != NULL ) {
			destrect.w = image->w;
			destrect.h = image->h;
		} else printf( "image not prevoius loaded\n " );

		destrect.x = x;
		destrect.y = y;
		SDL_BlitSurface( image, NULL, destsur, &destrect );
	}
