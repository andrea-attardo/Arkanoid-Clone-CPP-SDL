
#include "bouncemovcomponent.h"


	BounceMovComponent::BounceMovComponent( Actor* own, json boundrectDescr ) {

		owner		= own;
		boundRect	= { boundrectDescr["x"], boundrectDescr["y"],
						boundrectDescr["w"], boundrectDescr["h"]};
		

	}


	void BounceMovComponent::update( const double deltatime ) {

		owner->setX( owner->getX() + ( owner->getV().x * deltatime ));
		owner->setY( owner->getY() + ( owner->getV().y * deltatime ) );

		
		//stop at bound rect
		if ( owner->getX() <= boundRect.x )
		{
			owner->setX( boundRect.x );
			owner->setVx( -owner->getV().x );
		}
        if ( owner->getX() + owner->getW() >= boundRect.w )
		{
			owner->setX( boundRect.w - owner->getW() );
			owner->setVx( -owner->getV().x );
		}

		if ( owner->getY() <= boundRect.y )
		{
			owner->setY( boundRect.y );
			owner->setVy( -owner->getV().y );
		}
		
		if ( owner->getY() + owner->getH() >= boundRect.h )
		{
			owner->setY( boundRect.h - owner->getH() );
			owner->setVy( -owner->getV().y );
		}
		

		/*
		if ( owner->getY() + owner->getH() >= boundRect.h )
		{
			owner->setX( boundRect.w / 2 );
			owner->setY( boundRect.h / 2 );
			
		}
		*/
		
	}



	
