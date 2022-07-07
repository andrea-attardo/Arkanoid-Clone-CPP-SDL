#ifndef FLOATMOVCOMPONENT_H
#define FLOATMOVCOMPONENT_H

#include "SDL.h"
#include "../engine.h"
#include "../actor.h"
#include "json.hpp"
using json = nlohmann::json;

class FloatMovComponent: public Component {
public:

    FloatMovComponent(Actor* act, double velocity);

    void update( const double deltatime );

    void keyAction( SDL_Scancode keypressed );

private:
    Engine* engine;
    Actor* actor;
    double vx;
    double vy;
    double v;

    void( Component::* pFunc )( SDL_Scancode );
};

#endif