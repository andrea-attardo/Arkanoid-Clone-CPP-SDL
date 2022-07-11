
#include <iostream>
#include "staticspritecomponent.h"


	StaticSpriteComponent::StaticSpriteComponent( std::string filename, Actor* act, json layoutDescr, int iact ) {

		actor			= act;

		iActor			= iact;
		xoffset			= layoutDescr["xoffset"];
		yoffset			= layoutDescr["yoffset"];
		repeat			= layoutDescr["repeat"];
		repeatoffset	= layoutDescr["repeatoffset"];

		actor->setX( (int)actor->getX() + ( xoffset * ( iActor % repeat ) ) );
		actor->setY( (int)actor->getY() + ( yoffset * ( iActor % repeat ) ) + ( repeatoffset * ( iActor / repeat ) ) );

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

		destrect.x = (int)actor->getX();
		destrect.y = (int)actor->getY();
		destrect.w = (int)actor->getW();
		destrect.h = (int)actor->getW();

		SDL_BlitSurface( image, NULL, destsur, &destrect );

	}

	
