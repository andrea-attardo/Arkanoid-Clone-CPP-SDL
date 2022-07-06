#include <iostream>
#include "inputsystem.h"


InputSystem::InputSystem() {}



void InputSystem::bindtokey( SDL_Scancode keypressed ) {

    /*
    if ( func )
    {
        observers.insert( { keypressed, func } );
    }
    else
    {
        std::cout << "function passed is empty" << std::endl;
    }
    */

}


void InputSystem::process() {

    const Uint8* state = SDL_GetKeyboardState( NULL );

    /*
    for ( auto& [keypressed, function] : observers ) {

        if ( state[keypressed] )
        {
            function( keypressed );
        }

    }
    */

}


