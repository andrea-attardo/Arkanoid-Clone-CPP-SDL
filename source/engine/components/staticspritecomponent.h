
#ifndef	STATICSPRITECOMPONENT_H
#define STATICSPRITECOMPONENT_H

#include <string>
#include "SDL.h"
#include "../actor.h"
#include "../component.h"

class StaticSpriteComponent: public Component { 

public:
	StaticSpriteComponent( std::string filename, Actor* actor );

	void load();

	void render( SDL_Surface* destsur );

private:
	SDL_Surface*	image;
	SDL_Rect		destrect;
	Actor*			pActor;
	std::string		imgpath;
};


#endif 
