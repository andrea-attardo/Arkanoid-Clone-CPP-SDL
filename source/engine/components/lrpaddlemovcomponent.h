#ifndef LRPADDLEMOVCOMPONENT_H
#define LRPADDLECOMPONENT_H

#include "SDL.h"
#include "../engine.h"
#include "../actor.h"
#include "json.hpp"
using json = nlohmann::json;

class LrPaddleMovComponent : public Component {
public:

    LrPaddleMovComponent( Actor* act, json boundrDescr, double velocity );

    void update( const double deltatime );

    void keyAction( SDL_Scancode keypressed );

private:
    Actor* actor;
    SDL_Rect boundRect;
    double vx;
    double vy;
    double v;

    Engine* engine;
    void( Component::* pFunc )( SDL_Scancode );
};

#endif