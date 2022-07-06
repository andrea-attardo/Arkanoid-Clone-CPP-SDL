#include <iostream>
#include "inputsystem.h"


InputSystem::InputSystem() {}



void InputSystem::bindtokey( SDL_Scancode keypressed, void ( Component::* pFunc )( SDL_Scancode ), Component* cmpinstance ) {

    cmpInstance = cmpinstance;
    
    if ( pFunc )
    {
        observers.insert( { keypressed, pFunc } );
    }
    else
    {
        std::cout << "function passed is empty" << std::endl;
    }
    

}


void InputSystem::process() {

    const Uint8* state = SDL_GetKeyboardState( NULL );

    
    for ( auto& i : observers ) {

        if ( state[i.first] )
        {
            ( *cmpInstance.*i.second )( i.first );
        }

    }
    

}


