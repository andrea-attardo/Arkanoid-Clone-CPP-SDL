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

    const SDL_Rect* bAABB = othercollider->getAABB();

    SDL_Point aAABBlt = { aAABB.x, aAABB.y };
    SDL_Point aAABBrt = { aAABB.x + aAABB.w, aAABB.y };
    SDL_Point aAABBlb = { aAABB.x, aAABB.y + aAABB.h };
    SDL_Point aAABBrb = { aAABB.x + aAABB.w, aAABB.y + aAABB.h };

    double actorX   = actor->getX();
    double actorY   = actor->getY();
    double actorVx  = actor->getVx();
    double actorVy  = actor->getVy();


    if ( typeid( *othercollider ) == typeid( KineticCollComponent ) )
    {

        if ( elasticity > othercollider->getPhysicsProp( "elasticity" ) ) //non mi piace getPhysicProp
        {
            //repositioning
            if ( SDL_PointInRect( &aAABBrt, bAABB ) &&
                 SDL_PointInRect( &aAABBrb, bAABB ) )
            {
                actor->setX( actorX - ( aAABB.x + aAABB.w - bAABB->x ) );
                actor->setVx( -actorVx );
            }
            else if ( SDL_PointInRect( &aAABBlt, bAABB ) &&
                      SDL_PointInRect( &aAABBlb, bAABB ) )
            {
                actor->setX( actorX + ( bAABB->x + bAABB->w - aAABB.x ) );
                actor->setVx( -actorVx );
            }
            else if ( SDL_PointInRect( &aAABBlb, bAABB ) &&
                      SDL_PointInRect( &aAABBrb, bAABB ) )
            {
                actor->setY( actorY - ( aAABB.y + aAABB.h - bAABB->y ) );
                actor->setVy( -actorVy );
            }
            else if ( SDL_PointInRect( &aAABBlt, bAABB ) &&
                      SDL_PointInRect( &aAABBrt, bAABB ) )
            {
                actor->setY( actorY + ( bAABB->y + bAABB->h - aAABB.y ) );
                actor->setVy( -actorVy );
            }
    
            else if ( SDL_PointInRect( &aAABBrb, bAABB ) )
            {
                //actor->setX( actorX - ( aAABB.x + aAABB.w - bAABB->x ) );
                actor->setY( actorY - ( aAABB.y + aAABB.h - bAABB->y ) );
                actor->setVy( -actorVy );
                
            }
            else if ( SDL_PointInRect( &aAABBlb, bAABB ) )
            {
                //actor->setX( actorX + ( bAABB->x + bAABB->w - aAABB.x ) );
                actor->setY( actorY - ( aAABB.y + aAABB.h - bAABB->y ) );
                actor->setVy( -actorVy );
              
            }
            else if ( SDL_PointInRect( &aAABBlt, bAABB ) )
            {
               // actor->setX( actorX + ( bAABB->x + bAABB->w - aAABB.x ) );
                actor->setY( actorY + ( bAABB->y + bAABB->h - aAABB.y ) );
                actor->setVy( -actorVy );
            }
            else if ( SDL_PointInRect( &aAABBrt, bAABB ) )
            {
                //actor->setX( actorX - ( aAABB.x + aAABB.w - bAABB->x ) );
                actor->setY( actorY + ( bAABB->y + bAABB->h - aAABB.y ) );
                actor->setVy( -actorVy );
            }

        }



        
        if ( kineticEn + elasticity <= othercollider->getPhysicsProp( "kineticEn" ) )
        {
            //provvisorio, va eliminato l'actor dalla memoria e i suoi component
            actor->setX( -100 );
            actor->setY( -100 );
        }
        

    }


}

            

