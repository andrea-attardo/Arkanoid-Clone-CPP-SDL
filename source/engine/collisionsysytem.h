
#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include <vector>
#include "SDL.h"

class ColliderComponent;

class CollisionSystem {

public:
    CollisionSystem();

    void process();

    void registerColliders( ColliderComponent* collider );

    void deregisterColliders( ColliderComponent* collider );

private:
    std::vector<ColliderComponent*>  colliders;

};

#endif // !COLLISIONSYSTEM_H

