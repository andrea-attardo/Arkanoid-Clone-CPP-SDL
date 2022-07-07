/*
#include "collisionsysytem.h"


CollisionSystem::CollisionSystem() {}


void CollisionSystem::process() {

    for ( SDL_Rect& a : colliders ) {
        for ( SDL_Rect& b : colliders ) {

            if ( ( a.x != b.x ) &&
                 ( a.y != b.y ) &&
                 ( a.w != b.w ) &&
                 ( a.h != b.h )  ) {

                if ( SDL_HasIntersection( &a, &b ) ) {
                    collcmpInstance->onCollision( &b );
                }
            }

        }
    }
}


void CollisionSystem::registerColliders( const SDL_Rect* collider, ColliderComponent* cmpinstnc ) {

    colliders.push_back( *collider );

    collcmpInstance = cmpinstnc;

}


void CollisionSystem::deregisterColliders( const SDL_Rect* collider ) {

    std::vector<SDL_Rect>::iterator it = std::find( colliders.begin(), colliders.end(), &collider );
    colliders.erase( it );

}
*/
