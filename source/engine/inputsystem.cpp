#include <cstdio>
#include "SDL.h"
#include "inputsystem.h"

InputSystem::InputSystem() {

   //map
}


void InputSystem::process() {

    const Uint8* state = SDL_GetKeyboardState( NULL );
    if ( state[SDL_SCANCODE_RIGHT] ) {
        printf( "right is pressed.\n" );
    }

}
