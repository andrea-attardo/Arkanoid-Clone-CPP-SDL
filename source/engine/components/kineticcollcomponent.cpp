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
            //actor->setX( actor->getX() - actor->getW() );
            actor->setY( actor->getY() - actor->getH() );
            actor->setVy( -( actor->getVy() ) );
            //actor->setVx( -( actor->getVx() ) );
        }

        if ( kineticEn + elasticity <= othercollider->getPhysicsProp( "kineticEn" ) )
        {
            //provvisorio, va eliminato l'actor dalla memoria e i suoi component
            actor->setX( -100 );
            actor->setY( -100 );          
        }

    }
      
}
