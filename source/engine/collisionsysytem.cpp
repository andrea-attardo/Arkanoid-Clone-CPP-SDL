
#include "collisionsysytem.h"
#include "components/collidercomponent.h"

CollisionSystem::CollisionSystem() {}


void CollisionSystem::process() {

    for ( ColliderComponent* a : colliders ) {
        for ( ColliderComponent* b : colliders ) {

            if ( ( a->getAABB()->x != b->getAABB()->x ) ||
                 ( a->getAABB()->y != b->getAABB()->y ) ||
                 ( a->getAABB()->w != b->getAABB()->w ) ||
                 ( a->getAABB()->h != b->getAABB()->h ) ) {

                if ( SDL_HasIntersection( a->getAABB(), b->getAABB() ) ) {
                    a->onCollision(b);
                    // non serve b->onCollision(a); perche nel ciclo for succede b->oncollisioon(b)
                }
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

