/*
#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "SDL.h"
#include "../engine.h"
#include "../actor.h"
#include "json.hpp"
using json = nlohmann::json;

class ColliderComponent : public Component {

public:

    ColliderComponent(Actor* act, json AABB);

    void load();

    void update( const double deltatime );

    void onCollision(const SDL_Rect* otherCollider );

private:
    
    Actor* actor;
    SDL_Rect aabb;
    Engine* engine;

};



#endif // !COLLIDERCOMPONENT_H
*/