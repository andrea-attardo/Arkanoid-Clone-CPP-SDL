#include <iostream>
#include "kineticcollcomponent.h"
#include "../engine.h"


KineticCollComponent::KineticCollComponent( Actor* act, json AABB, json kineticprop ) : ColliderComponent(act, AABB) {

    kineticEn = kineticprop["kinen"];
    elasticity = kineticprop["elas"];
}


const double KineticCollComponent::getPhysicsProp(std::string prop) { 

        if ( prop == "kineticEn" ) return kineticEn; 
        if ( prop == "elasticity" ) return elasticity; 

}


void KineticCollComponent::onCollision( ColliderComponent* othercollider ) {

    std::cout << "collision happening" << std::endl;


    if ( typeid( *othercollider ) == typeid( KineticCollComponent ) )
    {

        if ( elasticity > othercollider->getPhysicsProp( "elasticity" ) ) //non mi piace getPhysicProp
        {

            //evita il rimbalzo interno se ci sono più intersezioni

            if ( aabb.x < othercollider->getAABB()->x &&
                 aabb.x + aabb.w < othercollider->getAABB()->x + othercollider->getAABB()->w )
            {
                actor->setX( actor->getX() - ( aabb.x + aabb.w - othercollider->getAABB()->x ) );
                actor->setVx( -( actor->getVx() ) );
            }

            else if ( aabb.x > othercollider->getAABB()->x )
            {
                if ( aabb.y + aabb.h < othercollider->getAABB()->y + othercollider->getAABB()->h )
                {
                    actor->setY( actor->getY() - ( aabb.y + aabb.h - othercollider->getAABB()->y ) );
                    actor->setVy( -( actor->getVy() ) );
                }
                else if ( aabb.y + aabb.h < othercollider->getAABB()->y + othercollider->getAABB()->h )
                {
                    actor->setY( actor->getY() + ( othercollider->getAABB()->y + othercollider->getAABB()->h - aabb.y ) );
                    actor->setVy( -( actor->getVy() ) );
                }
                else
                {
                    actor->setX( actor->getX() + ( othercollider->getAABB()->x + othercollider->getAABB()->w - aabb.x  ) );
                    actor->setVx( -( actor->getVx() ) );
                }
                
            }

        }

        

    }


    if ( kineticEn + elasticity <= othercollider->getPhysicsProp( "kineticEn" ) )
    {
        //provvisorio, va eliminato l'actor dalla memoria e i suoi component
        actor->setX( -100 );
        actor->setY( -100 );
    }

}

            




        

    
      


/*
            else if ( ( aabb.y + aabb.h ) < othercollider->getAABB()->y + othercollider->getAABB()->h )
            {
                actor->setY( actor->getY() - ( aabb.y + aabb.h - othercollider->getAABB()->y ) );
                actor->setVy( -( actor->getVy() ) );
            }
            else if ( ( aabb.y + aabb.h ) > othercollider->getAABB()->y + othercollider->getAABB()->h )
            {
                actor->setY( actor->getY() + ( aabb.y + aabb.h - othercollider->getAABB()->y ) );
                actor->setVy( -( actor->getVy() ) );
            }
            */