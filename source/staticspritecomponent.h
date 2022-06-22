
#ifndef	STATICSPRITECOMPONENT_H
#define STATICSPRITECOMPONENT_H

#include "SDL.h"
#include "actor.h"
#include "component.h"

class StaticSpriteComponent: public Component { 

public:
	StaticSpriteComponent( const char* filename, Actor* actor );

	void load();

	void render( SDL_Surface* destsur, SDL_Rect& destrect );

	void update();


private:
	SDL_Surface*	image;
	Actor*			pActor;
	const char*		imgpath;
	int				x;
	int				y;
};


#endif 
