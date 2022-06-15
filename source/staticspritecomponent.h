
#ifndef	STATICSPRITECOMPONENT_H
#define STATICSPRITECOMPONENT_H

#include "SDL.h"

class StatiSpriteComponent { //public Component

public:
	StatiSpriteComponent();

//protected:
	void load( const char* imgpath );

	void render( SDL_Surface* destsur, SDL_Rect& destrect );

private:
	SDL_Surface* image;
	double			x;
	double			y;
	double			vx;
	double			vy;
};


#endif 
