#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <iostream>
#include "SDL.h"
#include <map>

class InputSystem {
public:

    InputSystem();

    void bindtokey( SDL_Scancode keypressed  );

    void process();

 

private:
    //void (*)(SDL_Scancode)
    //std::function<void( SDL_Scancode )>
    std::map< SDL_Scancode, int > observers;

    
};




#endif 
