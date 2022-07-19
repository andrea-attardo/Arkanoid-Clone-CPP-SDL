#include <iostream>
#include "lrmovcomponent.h"

LRMovComponent::LRMovComponent( Actor* act, json boundrDescr, double acceleration ) {

    actor = act;
    boundRect = { boundrDescr["x"], boundrDescr["y"],
                  boundrDescr["w"], boundrDescr["h"] };
    
    acc = acceleration;

    pFunc = &Component::keyAction;

    engine = Engine::instance();

    engine->getInputsys()->bindtokey( SDL_SCANCODE_LEFT, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_RIGHT, pFunc, this );
}



void LRMovComponent::update( const double deltatime ) {


    actor->setX( actor->getX() + ( actor->getV().x * deltatime ));
    actor->setY( actor->getY() + ( actor->getV().y * deltatime ) );

    //inertia
    if ( actor->getV().x > 0 )
    {
        actor->setVx( actor->getV().x -  ( 5 *  acc * deltatime ) );
    }
    else
    {
       actor->setVx( actor->getV().x + ( 5 * acc * deltatime ) );
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


void LRMovComponent::keyAction( SDL_Scancode keypressed ) {

    if ( keypressed == SDL_SCANCODE_LEFT )
    {
        actor->setVx( -acc );
    }

    if ( keypressed == SDL_SCANCODE_RIGHT )
    {
        actor->setVx( +acc );
    }


}
