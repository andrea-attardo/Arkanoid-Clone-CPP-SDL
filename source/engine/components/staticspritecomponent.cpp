
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
		if ( image == NULL ) 
		{
			std::cerr << "Fail to load " + imgpath << std::endl;
		}
		else
		{
			if ( image->w != pActor->getW() )
			{
				std::cerr << "Actor " << pActor->getName() 
						  << " width is different from loaded image." 
						  << std::endl;
			}

			if ( image->h != pActor->getH() )
			{
				std::cerr << "Actor " << pActor->getName()
						  << " heigth is different from loaded image." 
						  << std::endl;
			}
		}

	}


	void StaticSpriteComponent::render( SDL_Surface* destsur ) {

		destrect.x = pActor->getX();
		destrect.y = pActor->getY();
		destrect.w = pActor->getW();
		destrect.h = pActor->getW();
		SDL_BlitSurface( image, NULL, destsur, &destrect );

	}

	
