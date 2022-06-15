
#include <cstdio>
#include "component.h"
#include "staticspritecomponent.h"


	StaticSpriteComponent::StaticSpriteComponent( const char* filename, Actor* actor ) {
		pActor			= actor;
		image			= NULL;
		imgpath			= filename;
		x				= actor->getX();
		y				= actor->getY();
	}


	void StaticSpriteComponent::load() {
		image = SDL_LoadBMP( imgpath );
		if ( image == NULL ) {
			printf( "Loading image %s failed\n", imgpath );
		}
	}


	 void StaticSpriteComponent::render( SDL_Surface* destsur, SDL_Rect& destrect ) {
		if ( image != NULL ) {
			destrect.w = image->w;
			destrect.h = image->h;
		} else printf( "image not prevoius loaded\n " );

		destrect.x = pActor->getX();
		destrect.y = pActor->getY();
		SDL_BlitSurface( image, NULL, destsur, &destrect );
	}

	 void StaticSpriteComponent::update(){}

