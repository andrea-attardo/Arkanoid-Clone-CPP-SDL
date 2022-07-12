
#include "collisionsysytem.h"
#include "components/collidercomponent.h"

CollisionSystem::CollisionSystem() {}


void CollisionSystem::process() {

    for ( ColliderComponent* a : colliders ) {

        for ( ColliderComponent* b : colliders ) {

            if ( !SDL_RectEquals( a->getAABB(), b->getAABB() ) && 
                  SDL_HasIntersection( a->getAABB(), b->getAABB() ) ) 
            {
                a->onCollision(b);
            }

        }

    }

}


void CollisionSystem::registerColliders( ColliderComponent* collider ) {
    
    colliders.push_back( collider );
 
}


void CollisionSystem::deregisterColliders( ColliderComponent* collider ) {

    //da provare
    /*
    std::vector<SDL_Rect>::iterator it = std::find( colliders.begin(), colliders.end(), collider );
    colliders.erase( it );
    */

}

