
#include <iostream>
#include <fstream>
#include "scenefactory.h"
#include "actor.h"
#include "components/staticspritecomponent.h"
#include "components/bouncemovcomponent.h"
#include "components/pathmovcomponent.h"
#include "components/floatmovcomponent.h"
#include "components/lrmovcomponent.h"
#include "components/collidercomponent.h"
#include "components/kineticcollcomponent.h"
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

            json layoutDescr = actorDescr["startlayout"];
            for ( int iAct = 0; iAct < layoutDescr["count"]; iAct++ ) {

                Actor* actor = new Actor( actorDescr );

                for ( json compDescr : actorDescr["components"] ) {
                    if ( compDescr["type"] == "StaticSpriteComponent" )
                    {
                        StaticSpriteComponent* sprite = new StaticSpriteComponent( compDescr["filename"], actor, layoutDescr, iAct );
                        actor->addComponent( sprite );
                    }
                    if ( compDescr["type"] == "BounceMovComponent" )
                    {
                        BounceMovComponent* bounce = new BounceMovComponent( actor, compDescr["boundrect"] );
                        actor->addComponent( bounce );
                    }
                    if ( compDescr["type"] == "PathMovComponent" )
                    {
                        PathMovComponenet* path = new PathMovComponenet( actor, compDescr["path"] );
                        actor->addComponent( path );
                    }
                    if ( compDescr["type"] == "FloatMovComponent" )
                    {
                        FloatMovComponent* floating = new FloatMovComponent( actor, compDescr["boundrect"], compDescr["acc"] );
                        actor->addComponent( floating );
                    }
                    if ( compDescr["type"] == "LRMovComponent" )
                    {
                        LRMovComponent* leftright = new LRMovComponent( actor, compDescr["boundrect"], compDescr["acc"] );
                        actor->addComponent( leftright );
                    }
                    if ( compDescr["type"] == "KineticCollComponent" )
                    {
                        KineticCollComponent* kineticcollider = new KineticCollComponent( actor, compDescr["aabb"], compDescr["kineticprop"] );
                        actor->addComponent( kineticcollider );
                    }

                }

                scene->addActor( actor );
            }
        }
        return scene;
    }

}