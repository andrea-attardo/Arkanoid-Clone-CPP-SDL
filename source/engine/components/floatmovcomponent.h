#ifndef FLOATMOVCOMPONENT_H
#define FLOATMOVCOMPONENT_H

#include <functional>
#include "SDL.h"
#include "../engine.h"
#include "../actor.h"
#include "../component.h"


class FloatMovComponent : public Component {
public:

    FloatMovComponent(Actor* act);

    void update( const double deltatime );

    void direction( SDL_Scancode keypressed );

private:
    Engine* engine;
    Actor* actor;
    double vx;
    double vy;


};

#endif