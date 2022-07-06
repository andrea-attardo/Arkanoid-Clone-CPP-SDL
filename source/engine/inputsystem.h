#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <iostream>
#include "SDL.h"
#include <map>
#include <functional>

class InputSystem {
public:

    InputSystem();

    void bindtokey( SDL_Scancode keypressed, std::function<void( SDL_Scancode )> func );

    void process();

 

private:
    //void (*)(SDL_Scancode)
    //std::function<void( SDL_Scancode )>
    std::map< SDL_Scancode, std::function<void( SDL_Scancode )>  > observers;

    
};




#endif 
