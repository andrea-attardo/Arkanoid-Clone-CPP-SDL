#include <iostream>
#include "../engine.h"
#include "floatmovcomponent.h"

FloatMovComponent::FloatMovComponent( Actor* act, json boundrDescr, double velocity ) {

    actor = act;
    boundRect = { boundrDescr["x"], boundrDescr["y"],
                  boundrDescr["w"], boundrDescr["h"] };
    vx = 0.0;
    vy = 0.0;
    v = velocity;

    pFunc = &Component::keyAction;
   
    engine  = Engine::instance();

    engine->getInputsys()->bindtokey( SDL_SCANCODE_UP, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_DOWN, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_LEFT, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_RIGHT, pFunc, this );

    
}



void FloatMovComponent::update(const double deltatime) {

    actor->setX( actor->getX() + ( vx * deltatime ) );
    actor->setY( actor->getY() + ( vy * deltatime ) );

    //inertia
    ( vx > 0 ) ? ( vx -= v * deltatime ) : ( vx += v * deltatime );
    ( vy > 0 ) ? ( vy -= v * deltatime ) : ( vy += v * deltatime );

    
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
        vy = -v ;
    }

    if ( keypressed == SDL_SCANCODE_DOWN )
    {
        vy = +v;
    }

    if ( keypressed == SDL_SCANCODE_LEFT )
    {
        vx = -v;
    }

    if ( keypressed == SDL_SCANCODE_RIGHT )
    {
        vx = +v;
    }


}

