#include <iostream>
#include "lrpaddlemovcomponent.h"

LrPaddleMovComponent::LrPaddleMovComponent( Actor* act, json boundrDescr, double velocity ) {

    actor = act;
    boundRect = { boundrDescr["x"], boundrDescr["y"],
                  boundrDescr["w"], boundrDescr["h"] };
    vx = 0.0;
    vy = 0.0;
    v = velocity;

    pFunc = &Component::keyAction;

    engine = Engine::instance();

    engine->getInputsys()->bindtokey( SDL_SCANCODE_LEFT, pFunc, this );
    engine->getInputsys()->bindtokey( SDL_SCANCODE_RIGHT, pFunc, this );
}



void LrPaddleMovComponent::update( const double deltatime ) {


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
        
}


void LrPaddleMovComponent::keyAction( SDL_Scancode keypressed ) {

    if ( keypressed == SDL_SCANCODE_LEFT )
    {
        vx = -v;
    }

    if ( keypressed == SDL_SCANCODE_RIGHT )
    {
        vx = +v;
    }


}
