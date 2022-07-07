/*
#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include <vector>
#include "SDL.h"
#include "components/collidercomponent.h"

class CollisionSystem {

public:
    CollisionSystem();

    void process();

    void registerColliders( const SDL_Rect* collider, ColliderComponent* collcmpinstnc );

    void deregisterColliders( const SDL_Rect* collider );

private:
    std::vector<SDL_Rect> colliders;
    ColliderComponent*            collcmpInstance;
};

#endif // !COLLISIONSYSTEM_H
*/
