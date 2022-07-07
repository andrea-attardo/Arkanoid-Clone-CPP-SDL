/*
#include <iostream>
#include "collidercomponent.h"


ColliderComponent::ColliderComponent( Actor* act, json AABB ) {

    actor = act;
    aabb.w = AABB["w"];
    aabb.h = AABB["h"];

    engine = Engine::instance();
}

void ColliderComponent::load() {

    engine->getCollisionsys()->registerColliders( &aabb, this );

}

void ColliderComponent::update( const double deltatime ) {

    aabb.x = actor->getX();
    aabb.y = actor->getY();

}

void ColliderComponent::onCollision( const SDL_Rect* otherCollider ) {

    std::cout << "collision happening" << std::endl;

}
*/