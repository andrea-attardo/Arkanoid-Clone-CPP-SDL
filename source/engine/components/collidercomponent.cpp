
#include <iostream>
#include "collidercomponent.h"
#include "../engine.h"


ColliderComponent::ColliderComponent( Actor* act, json AABB ) { //fare due collider

    actor   = act;

    aabb.x  = (int)actor->getX();
    aabb.y  = (int)actor->getY();
    aabb.w  = AABB["w"];
    aabb.h  = AABB["h"];

    if ( aabb.w != (int)actor->getW() || aabb.h != (int)actor->getH() )
    {
        std::cerr << "aabb has different size than sprite size" << std::endl;
    }

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

void ColliderComponent::onCollision( ColliderComponent* othercollider ) {

    std::cout << "collision happening" << std::endl;

    //if othercollider name == 

    //fai delle cose all'altro collider
    othercollider->actor->setVy( -( othercollider->actor->getVy() ) );
    //fai delle cose a te stesso
    //actor->
}
