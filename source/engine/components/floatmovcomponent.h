#ifndef FLOATMOVCOMPONENT_H
#define FLOATMOVCOMPONENT_H

#include "SDL.h"
#include "../engine.h"
#include "../actor.h"

class FloatMovComponent: public Component {
public:

    FloatMovComponent(Actor* act);

    void update( const double deltatime );

    void keyAction( SDL_Scancode keypressed );

private:
    Engine* engine;
    Actor* actor;
    double vx;
    double vy;

    void( Component::* pFunc )( SDL_Scancode );
};

#endif