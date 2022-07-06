#include "floatmovcomponent.h"

FloatMovComponent::FloatMovComponent( Actor* act ) {

   
    engine = Engine::instance();

    //engine->getInputsys()->bindtokey( SDL_SCANCODE_UP, []( SDL_Scancode ) -> void {
    //    std::cout << "func direction called, yeah" << "\n"; } ); 

    //engine->getInputsys()->bindtokey( SDL_SCANCODE_DOWN, func);
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


void FloatMovComponent::direction( SDL_Scancode keypressed ) {

    std::cout << "func direction called, yeah" << "\n";


}