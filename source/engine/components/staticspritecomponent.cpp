
#include <iostream>
#include "staticspritecomponent.h"


	StaticSpriteComponent::StaticSpriteComponent( std::string filename, Actor* act ) {

		actor			= act;
		image			= NULL;
		imgpath			= filename;
		destrect		= { 0, 0, 0, 0 };

	}


	void StaticSpriteComponent::load() {

		image = SDL_LoadBMP( imgpath.c_str() );
		if ( image == NULL ) 
		{
			std::cerr << "Fail to load " + imgpath << std::endl;
		}
		else
		{
			if ( image->w != actor->getW() )
			{
				std::cerr << "Actor " << actor->getName() 
						  << " width is different from loaded image." 
						  << std::endl;
			}

			if ( image->h != actor->getH() )
			{
				std::cerr << "Actor " << actor->getName()
						  << " heigth is different from loaded image." 
						  << std::endl;
			}
		}

	}


	void StaticSpriteComponent::render( SDL_Surface* destsur ) {

		destrect.x = actor->getX();
		destrect.y = actor->getY();
		destrect.w = actor->getW();
		destrect.h = actor->getW();
		SDL_BlitSurface( image, NULL, destsur, &destrect );

	}

	
