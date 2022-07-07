#include <iostream>
#include "floatmovcomponent.h"

FloatMovComponent::FloatMovComponent( Actor* act, double velocity ) {

    pFunc   = &Component::keyAction;
   
    engine  = Engine::instance();

    engine->getInputsys()->bindtokey( SDL_SCANCODE_UP, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_DOWN, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_LEFT, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_RIGHT, pFunc, this );

    actor   = act;
    vx      = 0.0;
    vy      = 0.0;
    v       = velocity;
}



void FloatMovComponent::update(const double deltatime) {

    actor->setX( actor->getX() + ( vx * deltatime ) );
    actor->setY( actor->getY() + ( vy * deltatime ) );

    //inertia
    ( vx > 0 ) ? ( vx -= v * deltatime ) : ( vx += v * deltatime );
    ( vy > 0 ) ? ( vy -= v * deltatime ) : ( vy += v * deltatime );

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