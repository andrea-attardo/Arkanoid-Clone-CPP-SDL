
#include <iostream>
#include "staticspritecomponent.h"


	StaticSpriteComponent::StaticSpriteComponent( std::string filename, Actor* actor ) {

		pActor			= actor;
		image			= NULL;
		imgpath			= filename;
		destrect		= { 0, 0, 0, 0 };
	}


	void StaticSpriteComponent::load() {
		image = SDL_LoadBMP( imgpath.c_str() );
		if ( image == NULL ) {
			std::cerr << "Fail to load " + imgpath << std::endl;
		} 
	}


	void StaticSpriteComponent::render( SDL_Surface* destsur ) {
		if ( image != NULL ) {
			destrect.w = image->w;
			destrect.h = image->h;
		} else std::cerr << "Fail to load " + imgpath << std::endl;

		destrect.x = pActor->getX();
		destrect.y = pActor->getY();
		SDL_BlitSurface( image, NULL, destsur, &destrect );
	}

	
