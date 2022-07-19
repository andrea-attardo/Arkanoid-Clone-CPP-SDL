
#ifndef BOUNCECOLLCOMPONENT_H
#define BOUNCECOLLCOMPONENT_H

#include "SDL.h"
#include "../actor.h"
#include "collidercomponent.h"
#include "json.hpp"

using json = nlohmann::json;

class Engine;



class KineticCollComponent: public ColliderComponent  {


public:

    KineticCollComponent( Actor* act, json AABB, json kineticprop );

    void onCollision( ColliderComponent* othercollider );

    double getKineticEn() { return kineticEn; }
    double getElasticity() { return elasticity; }

private:

    double kineticEn;  
    double elasticity; 
};



#endif // !COLLIDERCOMPONENT_H