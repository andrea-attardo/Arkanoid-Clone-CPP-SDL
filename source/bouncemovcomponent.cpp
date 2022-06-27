#include "bouncemovcomponent.h"


	BounceMovComponent::BounceMovComponent( Actor * actor ) {

		pActor		= actor;
		boundRect = { 0, 0, 0, 0 };
		vx			= 0;
		vy			= 0;

	}


	void BounceMovComponent::update() {

		pActor->setX( pActor->getX() + vx );
		pActor->setY( pActor->getY() + vy );

		if ( ( pActor->getX() ) < 0 || ( pActor->getX() ) >= boundRect.w )
		{
			vx = -vx;
		}

		if ( ( pActor->getY() ) < 0 || ( pActor->getY() ) >= boundRect.h )
		{
			vy = -vy;
		}

	}

	void BounceMovComponent::setBoundRect( const int& x, const int& y, const int& w, const int& h ) {
		boundRect = { x, y, w, h };
	}

	
