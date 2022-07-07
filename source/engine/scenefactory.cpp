
#include <iostream>
#include <fstream>
#include "scenefactory.h"
#include "actor.h"
#include "component.h"
#include "components/staticspritecomponent.h"
#include "components/bouncemovcomponent.h"
#include "components/pathmovcomponent.h"
#include "components/floatmovcomponent.h"
#include "components/lrpaddlemovcomponent.h"
#include "json.hpp"
using json = nlohmann::json;

Scene* SceneFactory::makeScene( std::string fileName ) {

    std::ifstream sceneFile;
    sceneFile.open( fileName );
    if ( sceneFile.fail() ) {
        std::cerr << ( "Error in " + fileName );
        return NULL;
    }
    else
    {
        Scene* scene = new Scene;
        json sceneDescriptor;
        sceneFile >> sceneDescriptor;

        for ( json actorDescr : sceneDescriptor["actors"] ) {
            Actor* actor = new Actor( actorDescr );

            for ( json compDescr : actorDescr["components"] ) {
                if ( compDescr["type"] == "StaticSpriteComponent" )
                {
                    StaticSpriteComponent* sprite = new StaticSpriteComponent( compDescr["filename"], actor );
                    actor->addComponent( sprite );
                }
                if ( compDescr["type"] == "BounceMovComponent" )
                {
                    BounceMovComponent* bounce = new BounceMovComponent( actor, compDescr, compDescr["boundrect"] );
                    actor->addComponent( bounce );
                }
                if ( compDescr["type"] == "PathMovComponent" )
                {
                    PathMovComponenet* path = new PathMovComponenet( actor, compDescr["path"] );
                    actor->addComponent( path );
                }
                if ( compDescr["type"] == "FloatMovComponent" )
                {
                    FloatMovComponent* floating = new FloatMovComponent( actor, compDescr["boundrect"], compDescr["v"] );
                    actor->addComponent( floating );
                }
                if ( compDescr["type"] == "LrPaddleMovComponent" )
                {
                    LrPaddleMovComponent* lrpaddling = new LrPaddleMovComponent( actor, compDescr["boundrect"], compDescr["v"] );
                    actor->addComponent( lrpaddling );
                }
                /*
                if ( compDescr["type"] == "ColliderComponent" )
                {
                    ColliderComponent* collider = new ColliderComponent( actor, compDescr["aabb"] );
                    actor->addComponent( collider );
                }
                */

            }

            scene->addActor( *actor );
        }
        return scene;
    }

}