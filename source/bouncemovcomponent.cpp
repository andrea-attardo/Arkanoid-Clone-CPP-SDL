#include "bouncemovcomponent.h"
#include <iostream>


	BounceMovComponent::BounceMovComponent( Actor * actor ) {

		pActor		= actor;
		boundRect	= { 0, 0, 0, 0 };
		vx			= 0;
		vy			= 0;

	}


	void BounceMovComponent::update( const double deltatime ) {

		pActor->setX( pActor->getX() + ( vx * deltatime ) );
		//pActor->setY( pActor->getY() + ( vy * deltatime ) );

		if ( pActor->getX() <= boundRect.x || pActor->getX() + 64 >= boundRect.w  ) // numero 64 da cambiare
		{
			vx = -vx;
		}

		/*
		if ( ( ( pActor->getY() ) < boundRect.y || ( pActor->getY() ) >= boundRect.h ) && deltatime != 0 )
		{
			vy = -vy;
		}
		*/
	}

	void BounceMovComponent::setBoundRect( const int& x, const int& y, const int& w, const int& h ) {
		boundRect = { x, y, w, h };
	}

	
