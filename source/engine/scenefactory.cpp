
#include <iostream>
#include <fstream>
#include "scenefactory.h"
#include "actor.h"
#include "component.h"
#include "../engine/components/staticspritecomponent.h"
#include "../engine/components/bouncemovcomponent.h"
#include "../engine/components/pathmovcomponent.h"
#include "../engine/components/floatmovcomponent.h"
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
                else if ( compDescr["type"] == "BounceMovComponent" )
                {
                    BounceMovComponent* bounce = new BounceMovComponent( actor, compDescr, compDescr["boundrect"] );
                    actor->addComponent( bounce );
                }
                else if ( compDescr["type"] == "PathMovComponent" )
                {
                    PathMovComponenet* path = new PathMovComponenet( actor, compDescr["path"] );
                    actor->addComponent( path );
                }
                if ( compDescr["type"] == "FloatMovComponent" )
                {
                    FloatMovComponent* floating = new FloatMovComponent( actor );
                    actor->addComponent( floating );
                }

            }

            scene->addActor( *actor );
        }
        return scene;
    }

}