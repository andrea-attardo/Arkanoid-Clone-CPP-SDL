
#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include "SDL.h"
#include "../actor.h"
#include "json.hpp"
using json = nlohmann::json;

class Engine;

class ColliderComponent : public Component {

public:

    ColliderComponent(Actor* act, json AABB);

    void load();

    void update( const double deltatime );

    const SDL_Rect* getAABB() { return &aabb; }

    virtual void onCollision( ColliderComponent* othercollider ) {}

    virtual const double getPhysicsProp( std::string prop ) = 0;

protected:
    
    Actor* actor;
    SDL_Rect aabb;
    Engine* engine;

};



#endif // !COLLIDERCOMPONENT_H
