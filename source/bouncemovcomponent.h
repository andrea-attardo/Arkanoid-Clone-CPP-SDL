
#ifndef BOUNCEMOVCOMPONENT_H
#define BOUNCEMOVCOMPONENT_H

#include "SDL.h"
#include "actor.h"
#include "component.h"

class BounceMovComponent: public Component {

public:

	BounceMovComponent( SDL_Surface* winsur, Actor* actor );

	void load();

	void update();

	void render( SDL_Surface* destsur, SDL_Rect& destrect );


private:
	double vx;
	double vy;
	SDL_Surface* windowSur;
	Actor* pActor;
};


#endif 