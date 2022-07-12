
#include <iostream>
#include "collidercomponent.h"
#include "../engine.h"


ColliderComponent::ColliderComponent( Actor* act, json AABB ) {

    engine  = Engine::instance();

    actor   = act;

    aAABB.x  = (int)actor->getX();
    aAABB.y  = (int)actor->getY();
    aAABB.w  = AABB["w"];
    aAABB.h  = AABB["h"];

    if ( aAABB.w != (int)actor->getW() || aAABB.h != (int)actor->getH() )
    {
        std::cerr << "aAABB has different size than sprite size" << std::endl;
    }


}

void ColliderComponent::load() {

    engine->getCollisionsys()->registerColliders( this );

}

void ColliderComponent::update( const double deltatime ) {

    aAABB.x = (int)actor->getX();
    aAABB.y = (int)actor->getY();

}

