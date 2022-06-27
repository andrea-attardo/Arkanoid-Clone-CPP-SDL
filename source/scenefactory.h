#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H


#include <iostream>
#include <fstream>
#include <typeinfo>
#include "scene.h"
#include "actor.h"
#include "component.h"
#include "staticspritecomponent.h"
#include "bouncemovcomponent.h"
#include "json.hpp"
using json = nlohmann::json;

class SceneFactory{
public:
    SceneFactory() {}

    Scene loadSceneFromFile( std::string fileName ) {
        
            std::ifstream sceneFile( fileName ); //c'era .open(
            if ( sceneFile.fail() ) {
                std::cerr << ( "Error in " + fileName);
            }
            else
            {
                
                json sceneDescriptor;
                sceneFile >> sceneDescriptor;

                Scene scene;

                for ( json actorDescr : sceneDescriptor["actors"] ) {

                    Actor actor;
                    actor.setName( actorDescr["name"]);
                    actor.setX( actorDescr["x"] );
                    actor.setY( actorDescr["y"] );

                    Component comp;
                    for ( json compDescr : actorDescr["components"] ) {
                        if ( compDescr["type"] == "StaticSpriteComponent" )
                        {
                            StaticSpriteComponent sprite( compDescr["filename"], &actor );
                            comp = sprite;
                        }
                        else if ( compDescr["type"] == "BounceMovComponent" )
                        {
                            BounceMovComponent bounce( &actor );
                            json boundrectDescr = compDescr["boundrect"];
                            bounce.setBoundRect( boundrectDescr["x"], boundrectDescr["y"],
                                               boundrectDescr["w"], boundrectDescr["h"] );
                            bounce.setVx( compDescr["vx"] );
                            bounce.setVy( compDescr["vy"] );
                            comp = bounce;
                        }
                        actor.addComponent( &comp );
                    }

                    scene.addActor( &actor );

                }

                scene.load();
                return scene;
            }

    }
        
    
private:
    //std::ifstream sceneFile;
    //json sceneDescriptor;
};


#endif // !SCENEFACTORY_H
