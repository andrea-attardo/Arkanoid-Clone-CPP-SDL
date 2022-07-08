
#include "bouncemovcomponent.h"


	BounceMovComponent::BounceMovComponent( Actor * actor, json boundrectDescr ) {

		pActor		= actor;
		boundRect	= { boundrectDescr["x"], boundrectDescr["y"],
						boundrectDescr["w"], boundrectDescr["h"]};
		
	}


	void BounceMovComponent::update( const double deltatime ) {

		pActor->setX( pActor->getX() + ( pActor->getVx() * deltatime ) );
		pActor->setY( pActor->getY() + ( pActor->getVy() * deltatime ) );

		//da sistemare
		if ( pActor->getX() <= boundRect.x )
		{
			pActor->setX( boundRect.x );
			pActor->setVx( -(pActor->getVx()) );
		}
        else if ( pActor->getX() + pActor->getW() >= boundRect.w )
		{
			pActor->setX( boundRect.w - pActor->getW() );
			pActor->setVx( -( pActor->getVx() ) );
		}


		if ( pActor->getY() <= boundRect.y )
		{
			pActor->setY( boundRect.y );
			pActor->setVy( -( pActor->getVy() ) );
		}
		else if ( pActor->getY() + pActor->getH() >= boundRect.h )
		{
			pActor->setY( boundRect.h - pActor->getH() );
			pActor->setVy( -( pActor->getVy() ) );
		}

		
	}



	
