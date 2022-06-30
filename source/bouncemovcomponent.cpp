#include "bouncemovcomponent.h"
#include <iostream>


	BounceMovComponent::BounceMovComponent( Actor * actor, json actorDescr, json boundrectDescr ) {

		pActor		= actor;
		boundRect	= { boundrectDescr["x"], boundrectDescr["y"],
						boundrectDescr["w"], boundrectDescr["h"]};
		vx			= actorDescr["vx"];
		vy			= actorDescr["vy"];

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
        else if ( pActor->getX() + pActor->getW() >= boundRect.w )
		{
			pActor->setX( boundRect.w - pActor->getW() );
			vx = -vx;
		}

		if ( pActor->getY() <= boundRect.y )
		{
			pActor->setY( boundRect.y );
			vy = -vy;
		}
		else if ( pActor->getY() + pActor->getH() >= boundRect.h )
		{
			pActor->setY( boundRect.h - pActor->getH() );
			vy = -vy;
		}

		
	}



	
