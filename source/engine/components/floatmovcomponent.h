#ifndef FLOATMOVCOMPONENT_H
#define FLOATMOVCOMPONENT_H

#include "SDL.h"
#include "../actor.h"
#include "json.hpp"
using json = nlohmann::json;

class Engine;

class FloatMovComponent: public Component {
public:

    FloatMovComponent(Actor* act, json boundrDescr, double velocity );

    void update( const double deltatime );

    void keyAction( SDL_Scancode keypressed );

private:
    Actor* actor;
    SDL_Rect boundRect;
    double acc;

    Engine* engine;
    void( Component::* pFunc )( SDL_Scancode );
};

#endif