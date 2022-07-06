#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <iostream>
#include <map>
#include "SDL.h"
#include "component.h"

class InputSystem {
public:

    InputSystem();

    void bindtokey( SDL_Scancode keypressed, void (Component::*pFunc)( SDL_Scancode ), Component* cmpinstance );

    void process();

 

private:
   
    std::map< SDL_Scancode, void ( Component::* )( SDL_Scancode ) > observers;
    
    Component* cmpInstance;
    
};




#endif 
