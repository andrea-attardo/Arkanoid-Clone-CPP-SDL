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

    vx          = ( nextlegX - currentlegX ) / nextlegTime;
    vy          = ( nextlegY - currentlegY ) / nextlegTime;

}


void PathMovComponenet::update( const double deltatime ) {
   
    int distanceXs = nextlegX - pActor->getX();
    int distanceYs = nextlegY - pActor->getY();

    std::cout << distanceXs << " | " << distanceYs << "\n";

    //da sistemare  
    //funziona ma: 
    //1: se sposto la finestra quando sta vicino ai bordi se ne va
    //2: se cambio la posizione iniziale della x e della y se ne va 
    if ( distanceXs != 0 || distanceYs != 0 ) // <- problema con questa cosa qua
    {
        pActor->setX( pActor->getX() + ( vx * deltatime ) );
        pActor->setY( pActor->getY() + ( vy * deltatime ) );
        
    } 
    else
    {
        currentleg = nextleg;
        currentlegX = path[currentleg][0];
        currentlegY = path[currentleg][1];

        nextleg = ++currentleg % path.size();
        nextlegX = path[nextleg][0];
        nextlegY = path[nextleg][1];
        nextlegTime = path[nextleg][2];

        vx = ( nextlegX - currentlegX ) / nextlegTime;
        vy = ( nextlegY - currentlegY ) / nextlegTime;

    }
    
    
    
}