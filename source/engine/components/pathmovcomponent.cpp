#include "pathmovcomponent.h"


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

    nextlegTime = 0;
    distanceXs  = 0;
    distanceYs  = 0;   

}



void PathMovComponenet::update( const double deltatime ) {
    distanceXs = nextlegX - (int)pActor->getX();
    distanceYs = nextlegY - (int)pActor->getY();
    
    //da sistemare
    if ( ( pActor->getVx() > 0 && distanceXs >= 0 ) ||
         ( pActor->getVx() < 0 &&  distanceXs <  0 ) ||
         ( pActor->getVy() > 0 &&  distanceYs >= 0 ) ||
         ( pActor->getVy() < 0 &&  distanceYs <  0 ) )
    { 
        pActor->setX( pActor->getX() + ( pActor->getVx() * deltatime ) );
        pActor->setY( pActor->getY() + ( pActor->getVy() * deltatime ) );
    }
    else
    {
        nextleg = ++nextleg % path.size();
        nextlegX = path[nextleg][0];
        nextlegY = path[nextleg][1];
        nextlegTime = path[nextleg][2];

        pActor->setVx( ( nextlegX - (int)pActor->getX() ) / nextlegTime );
        pActor->setVy( ( nextlegY - (int)pActor->getY() ) / nextlegTime );

    }   
}