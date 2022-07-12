
#ifndef	STATICSPRITECOMPONENT_H
#define STATICSPRITECOMPONENT_H

#include <string>
#include "SDL.h"
#include "../actor.h"

class StaticSpriteComponent: public Component { 

public:
	StaticSpriteComponent( std::string filename, Actor* act, json layoutDescr, int iact );

	void load();

	void render( SDL_Surface* destsur );

private:
	SDL_Surface*	image;
	std::string		imgpath;
	SDL_Rect		destrect;

	Actor*			actor;
	int				iActor;
	int				xoffset;
	int				yoffset;
	int				perline;
	int				lineoffset;
};


#endif 
