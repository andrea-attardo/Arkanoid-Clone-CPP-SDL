#ifndef LRMOVCOMPONENT_H
#define LRMOVCOMPONENT_H

#include "SDL.h"
#include "../engine.h"
#include "../actor.h"
#include "json.hpp"
using json = nlohmann::json;

class LRMovComponent : public Component {
public:

    LRMovComponent( Actor* act, json boundrDescr, double velocity );

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