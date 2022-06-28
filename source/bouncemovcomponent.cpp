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
		pActor->setY( pActor->getY() + ( vy * deltatime ) );


		//fare refactoring
		if ( pActor->getX() <= boundRect.x )
		{
			pActor->setX( boundRect.x );
			vx = -vx;
		}

		if ( pActor->getX() + pActor->getW() >= boundRect.w )
		{

			pActor->setX( boundRect.w - pActor->getW() );
			vx = -vx;
		}

		if ( pActor->getY() <= boundRect.y )
		{
			pActor->setY( boundRect.y );
			vy = -vy;
		}

		if ( pActor->getY() + pActor->getH() >= boundRect.h )
		{

			pActor->setY( boundRect.h - pActor->getH() );
			vy = -vy;
		}

		
	}

	void BounceMovComponent::setBoundRect( const int& x, const int& y, const int& w, const int& h ) {
		boundRect = { x, y, w, h };
	}

	
