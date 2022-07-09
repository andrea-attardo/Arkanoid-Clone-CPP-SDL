
#include <iostream>
#include "collidercomponent.h"
#include "../engine.h"


ColliderComponent::ColliderComponent( Actor* act, json AABB ) {

    engine  = Engine::instance();

    actor   = act;

    aabb.x  = (int)actor->getX();
    aabb.y  = (int)actor->getY();
    aabb.w  = AABB["w"];
    aabb.h  = AABB["h"];

    if ( aabb.w != (int)actor->getW() || aabb.h != (int)actor->getH() )
    {
        std::cerr << "aabb has different size than sprite size" << std::endl;
    }


}

void ColliderComponent::load() {

    engine->getCollisionsys()->registerColliders( this );

}

void ColliderComponent::update( const double deltatime ) {

    aabb.x = (int)actor->getX();
    aabb.y = (int)actor->getY();

}

