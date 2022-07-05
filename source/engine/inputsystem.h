#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include <map>


class InputSystem {
public:

    InputSystem();

    void process();


private:


    //std::vector< SDL_Keysym, 
    // pointer to a function
    //std::function<int( int )> > observers;
    std::map<int, int> observers;

};




#endif 
