#include <iostream>
#include "../engine.h"
#include "floatmovcomponent.h"

FloatMovComponent::FloatMovComponent( Actor* act, json boundrDescr, double acceleration ) {

    actor = act;
    boundRect = { boundrDescr["x"], boundrDescr["y"],
                  boundrDescr["w"], boundrDescr["h"] };
    
    acc = acceleration;

    pFunc = &Component::keyAction;
   
    engine  = Engine::instance();

    engine->getInputsys()->bindtokey( SDL_SCANCODE_UP, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_DOWN, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_LEFT, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_RIGHT, pFunc, this );

    
}



void FloatMovComponent::update(const double deltatime) {

    actor->setX( actor->getX() + ( actor->getV().x * deltatime ));
    actor->setY( actor->getY() + ( actor->getV().y * deltatime ) );


    //inertia
    if ( actor->getV().x > 0 )
    {
        actor->setVx( actor->getV().x - ( acc * deltatime ) );
    }
    else
    {

        actor->setVx( actor->getV().x + ( acc * deltatime ) );
    }

    if ( actor->getV().y > 0 )
    {
        actor->setVy( actor->getV().y - ( acc * deltatime ) );
    }
    else
    {

        actor->setVy( actor->getV().y + ( acc * deltatime ) );
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

    if ( actor->getY() < boundRect.y )
    {
        actor->setY( boundRect.y );
    }

    if ( actor->getY() + actor->getH() > boundRect.h )
    {
        actor->setY( boundRect.h - actor->getH() );
    }
    
}


void FloatMovComponent::keyAction( SDL_Scancode keypressed ) {

    if ( keypressed == SDL_SCANCODE_UP )
    {
        actor->setVy( -acc );
    }

    if ( keypressed == SDL_SCANCODE_DOWN )
    {
        actor->setVy( +acc );
    }

    if ( keypressed == SDL_SCANCODE_LEFT )
    {
        actor->setVx( -acc );
    }

    if ( keypressed == SDL_SCANCODE_RIGHT )
    {
        actor->setVx( +acc );
    }


}

