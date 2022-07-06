#include <iostream>
#include "floatmovcomponent.h"

FloatMovComponent::FloatMovComponent( Actor* act ) {

    pFunc = &Component::keyAction;
    
   
    engine = Engine::instance();

    engine->getInputsys()->bindtokey( SDL_SCANCODE_DOWN, pFunc, this );

    //engine->getInputsys()->bindtokey( SDL_SCANCODE_UP, func);
    //engine->getInputsys()->bindtokey( SDL_SCANCODE_LEFT, func );
    //engine->getInputsys()->bindtokey( SDL_SCANCODE_RIGHT, func );

    actor = act;
    vx = 0.0;
    vy = 0.0;

}



void FloatMovComponent::update(const double deltatime) {

    actor->setX( actor->getX() + ( vx * deltatime ) );
    actor->setY( actor->getY() + ( vy * deltatime ) );

    //inertia
}


void FloatMovComponent::keyAction( SDL_Scancode keypressed ) {

    if ( keypressed == SDL_SCANCODE_DOWN )
    {
        vy = +100;
    }

}