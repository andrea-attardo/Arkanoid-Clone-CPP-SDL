#include <iostream>
#include "lrpaddlemovcomponent.h"

LrPaddleMovComponent::LrPaddleMovComponent( Actor* act, json boundrDescr, double velocity ) {

    actor = act;
    boundRect = { boundrDescr["x"], boundrDescr["y"],
                  boundrDescr["w"], boundrDescr["h"] };
    
    v = velocity;

    pFunc = &Component::keyAction;

    engine = Engine::instance();

    engine->getInputsys()->bindtokey( SDL_SCANCODE_LEFT, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_RIGHT, pFunc, this );
}



void LrPaddleMovComponent::update( const double deltatime ) {


    actor->setX( actor->getX() + ( actor->getVx() * deltatime ));
    actor->setY( actor->getY() + ( actor->getVy() * deltatime ) );

    //inertia
    if ( actor->getVx() > 0 )
    {
        actor->setVx( actor->getVx() - ( v * deltatime ) );
    }
    else
    {
       actor->setVx( actor->getVx() + ( v * deltatime ) );
    }

    if ( actor->getVy() > 0 )
    {
        actor->setVy( actor->getVy() - ( v * deltatime ) );
    }
    else
    {
        actor->setVy( actor->getVy() + ( v * deltatime ) );
    }



    //stop at bound rect
    if ( actor->getX() < boundRect.x ) 
    {
        actor->setX( boundRect.x );
    }

    if ( actor->getX() + actor->getW() > boundRect.w )
    {
        actor->setX( boundRect.w - actor->getW() );
    }
        
}


void LrPaddleMovComponent::keyAction( SDL_Scancode keypressed ) {

    if ( keypressed == SDL_SCANCODE_LEFT )
    {
        actor->setVx( -v );
    }

    if ( keypressed == SDL_SCANCODE_RIGHT )
    {
        actor->setVx( +v );
    }


}
