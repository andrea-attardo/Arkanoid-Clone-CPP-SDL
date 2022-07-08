
#include <iostream>
#include "collidercomponent.h"
#include "../engine.h"


ColliderComponent::ColliderComponent( Actor* act, json AABB ) {

    actor   = act;

    aabb.x  = (int)actor->getX();
    aabb.y  = (int)actor->getY();
    aabb.w  = AABB["w"];
    aabb.h  = AABB["h"];

    engine  = Engine::instance();

}

void ColliderComponent::load() {

    engine->getCollisionsys()->registerColliders( this );

}

void ColliderComponent::update( const double deltatime ) {

    aabb.x = (int)actor->getX();
    aabb.y = (int)actor->getY();

}

void ColliderComponent::onCollision(  ) {

    std::cout << "collision happening" << std::endl;
    //chiamerà la funzione
}
