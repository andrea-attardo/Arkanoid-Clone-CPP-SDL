#include "pathmovcomponent.h"
#include <iostream>


PathMovComponenet::PathMovComponenet( Actor* actor, json pathDescr ) {

    pActor = actor;
    
    for ( json& leg : pathDescr ) {

        std::array< double, 3> legA = { leg["x"], leg["y"], leg["time"] };

        path.push_back( legA );
      
    }

    nextleg     = 0;
    nextlegX    = path[nextleg][0];
    nextlegY    = path[nextleg][1];
    nextlegTime = path[nextleg][2];

    vx          = ( nextlegX - (int)pActor->getX() ) / nextlegTime;
    vy          = ( nextlegY - (int)pActor->getY() ) / nextlegTime;

}


void PathMovComponenet::update( const double deltatime ) {
   

    if ( vx > 0 && ( nextlegX - (int)pActor->getX() ) >= 0  )
    {
        pActor->setX( pActor->getX() + ( vx * deltatime ) );
        pActor->setY( pActor->getY() + ( vy * deltatime ) );  
    }
    else if ( vx < 0 && ( nextlegX - (int)pActor->getX() ) < 0 )
    {
        pActor->setX( pActor->getX() + ( vx * deltatime ) );
        pActor->setY( pActor->getY() + ( vy * deltatime ) );
    }
    else if ( vy > 0 && ( nextlegY - (int)pActor->getY() ) >= 0 )
    {
        pActor->setX( pActor->getX() + ( vx * deltatime ) );
        pActor->setY( pActor->getY() + ( vy * deltatime ) );
    }
    else if ( vy < 0 && ( nextlegY - (int)pActor->getY() ) < 0 )
    {
        pActor->setX( pActor->getX() + ( vx * deltatime ) );
        pActor->setY( pActor->getY() + ( vy * deltatime ) );
    }
    else
    {
        nextleg = ++nextleg % path.size();
        nextlegX = path[nextleg][0];
        nextlegY = path[nextleg][1];
        nextlegTime = path[nextleg][2];

        vx = ( nextlegX - (int)pActor->getX() ) / nextlegTime;
        vy = ( nextlegY - (int)pActor->getY() ) / nextlegTime;
    }   
}