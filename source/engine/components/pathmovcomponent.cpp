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
    vx          = 0;
    vy          = 0;

}


//fare refactoring
void PathMovComponenet::update( const double deltatime ) {
    distanceXs = nextlegX - (int)pActor->getX();
    distanceYs = nextlegY - (int)pActor->getY();
    
    if ( ( vx > 0 &&  distanceXs >= 0 ) ||
         ( vx < 0 &&  distanceXs <  0 ) ||
         ( vy > 0 &&  distanceYs >= 0 ) ||
         ( vy < 0 &&  distanceYs <  0 ) )
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