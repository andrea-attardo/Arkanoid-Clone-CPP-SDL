
#ifndef BOUNCEMOVCOMPONENT_H
#define BOUNCEMOVCOMPONENT_H

#include "actor.h"
#include "component.h"
#include "staticspritecomponent.h"

class BounceMovComponent: public Component {

public:

	BounceMovComponent( SDL_Surface* winsur, Actor* actor ) {
		windowSur = winsur;
		pActor = actor;
		vx	= 5.0;
		vy	= 5.0;
	}

	void load(){};

	void update() {

		pActor->setX( pActor->getX() + vx);
		pActor->setY( pActor->getY() + vy );

		if ( (pActor->getX()) < 0 || (pActor->getX()) >= windowSur->w )
		{
			vx = -vx;
		}

		if ( (pActor->getY()) < 0 || (pActor->getY()) >= windowSur->h )
		{
			vy = -vy;
		}

	}

	void render( SDL_Surface* destsur, SDL_Rect& destrect ) {};


private:
	double vx;
	double vy;
	SDL_Surface* windowSur;
	Actor* pActor;
};


#endif 