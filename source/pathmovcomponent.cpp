#include "pathmovcomponent.h"
#include <iostream>


PathMovComponenet::PathMovComponenet( Actor* actor, json pathDescr ) {

    pActor = actor;
    
    for ( json& leg : pathDescr ) {

        std::array< double, 3> legA = { leg["x"], leg["y"], leg["time"] };

        path.push_back( legA );
      
    }

    currentleg   = 0;
    currentlegX = path[currentleg][0];
    currentlegY = path[currentleg][1];

    nextleg     = 1;
    nextlegX    = path[nextleg][0];
    nextlegY    = path[nextleg][1];
    nextlegTime = path[nextleg][2];

   
    vx          = nextlegY - currentlegY / nextlegTime;
    vy          = nextlegY - currentlegY / nextlegTime;

}


void PathMovComponenet::update( const double deltatime ) {
   
    //da sistemare  
    if ( (int)pActor->getX() != (int)nextlegX && (int)pActor->getY() != (int)nextlegY )
    {
        pActor->setX( pActor->getX() + ( vx * deltatime ) );
        pActor->setY( pActor->getX() + ( vy * deltatime ) );
    }
    else
    {
        currentleg = nextleg;
        nextleg = ++nextleg % path.size();

        nextlegX = path[nextleg][0];
        nextlegY = path[nextleg][1];
        nextlegTime = path[nextleg][2];
        vx = nextlegX - currentlegX / nextlegTime;
        vy = nextlegY - currentlegY / nextlegTime;

    }
  
    
    
}