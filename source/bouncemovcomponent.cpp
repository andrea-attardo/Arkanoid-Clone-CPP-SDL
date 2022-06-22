#include "bouncemovcomponent.h"



	BounceMovComponent::BounceMovComponent( SDL_Surface * winsur, Actor * actor ) {
		windowSur = winsur;
		pActor = actor;
		vx = 5.0;
		vy = 5.0;
	}

	void BounceMovComponent::update() {

		pActor->setX( pActor->getX() + vx );
		pActor->setY( pActor->getY() + vy );

		if ( ( pActor->getX() ) < 0 || ( pActor->getX() ) >= windowSur->w )
		{
			vx = -vx;
		}

		if ( ( pActor->getY() ) < 0 || ( pActor->getY() ) >= windowSur->h )
		{
			vy = -vy;
		}

	}
