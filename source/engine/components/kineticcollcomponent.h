
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

    const double getPhysicsProp( std::string prop ); 


private:

    double kineticEn;  //in teoria massa * velocità
    double elasticity; //resistenza cinetica
};



#endif // !COLLIDERCOMPONENT_H