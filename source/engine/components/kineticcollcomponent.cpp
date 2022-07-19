#include <iostream>
#include "kineticcollcomponent.h"
#include "../engine.h"
#include "../../mathvec.h"



KineticCollComponent::KineticCollComponent( Actor* act, json AABB, json kineticprop ) : ColliderComponent(act, AABB) {

    kineticEn    = kineticprop["kinen"];
    elasticity   = kineticprop["elas"];

}


void KineticCollComponent::onCollision( ColliderComponent* othercollider ) {
    std::cout << "collision happening." << std::endl;
    
    const SDL_Rect* bAABB = othercollider->getAABB();
    const SDL_Point aCenter = { ( aAABB.x + aAABB.w ) / 2, ( aAABB.y + aAABB.h ) / 2 };
    const SDL_Point bCenter = { ( bAABB->x + bAABB->w ) / 2, ( bAABB->y + bAABB->h ) / 2 };

    Vector2 vec( aCenter.x - bCenter.x, bCenter.y - aCenter.y );
    double distanceab = vec.length();

    KineticCollComponent* kincoll = dynamic_cast<KineticCollComponent*>(othercollider);
    if ( kincoll != NULL )
    {
        if ( elasticity > kincoll->getElasticity() ) 
        {
            if ( distanceab < 100 )
            {
                actor->setVy( -actor->getV().y );
            }   
        }

        
        if ( kineticEn + elasticity <= kincoll->getKineticEn() )
        {
            //provvisorio, va eliminato l'actor dalla memoria e i suoi component
            actor->setX( -100 );
            actor->setY( -100 );
        }
        

    }
    else
    {
        std::cout << "Dynamic cast failed of KineticCollComponent" << std::endl;
    }


}

            

