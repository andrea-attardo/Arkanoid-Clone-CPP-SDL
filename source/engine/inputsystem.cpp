#include <iostream>
#include "inputsystem.h"


InputSystem::InputSystem() {

    cmpInstance = NULL;
}


void InputSystem::process() {

    const Uint8* state = SDL_GetKeyboardState( NULL );

    for ( auto& obs : observers ) {

        auto& keypressed = obs.first;
        auto& keyfunction = obs.second;

        if ( state[keypressed] )
        {
            ( *cmpInstance.*keyfunction )( keypressed );
        }

    }


}


void InputSystem::bindtokey( SDL_Scancode keypressed, void ( Component::* pFunc )( SDL_Scancode ), Component* cmpinstance ) {

    cmpInstance = cmpinstance;
    
    if ( pFunc != NULL )
    {
        observers.insert( { keypressed, pFunc } );
    }
    else
    {
        std::cerr << "function passed is empty" << std::endl;
    }
    
}





