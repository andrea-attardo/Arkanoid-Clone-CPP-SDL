#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SDL.h"
#include "actor.h"
#include "scene.h"
#include "actor.h"
#include "component.h"
#include "staticspritecomponent.h"
#include "bouncemovcomponent.h"
#include "json.hpp"
using json = nlohmann::json;

class Scene {

public:

	Scene();

    //private?
	void load();

	void update();

	void render( SDL_Surface* destsur );

	void addActor( Actor actor );

    void loadSceneFromFile( std::string fileName ) {

        sceneFile.open( fileName );
        if ( sceneFile.fail() ) {
            std::cerr << ( "Error in " + fileName );
        }
        else
        {

            json sceneDescriptor;
            sceneFile >> sceneDescriptor;

            for ( json actorDescr : sceneDescriptor["actors"] ) {
                Actor* actor = new Actor();
                actor->setName( actorDescr["name"] );
                actor->setX( actorDescr["x"] );
                actor->setY( actorDescr["y"] );
                
                for ( json compDescr : actorDescr["components"] ) {
                    if ( compDescr["type"] == "StaticSpriteComponent" )
                    {
                        StaticSpriteComponent* sprite = new StaticSpriteComponent( compDescr["filename"], actor );
                        actor->addComponent( sprite );
                    }
                    else if ( compDescr["type"] == "BounceMovComponent" )
                    {
                        BounceMovComponent* bounce = new BounceMovComponent ( actor );
                        json boundrectDescr = compDescr["boundrect"];
                        bounce->setBoundRect( boundrectDescr["x"], boundrectDescr["y"],
                                              boundrectDescr["w"], boundrectDescr["h"] );
                        bounce->setVx( compDescr["vx"] );
                        bounce->setVy( compDescr["vy"] );
                        actor->addComponent( bounce );
                    }
                    
                }

                this->addActor( *actor );

            }

            this->load();
        }

    }

private:
	std::vector<Actor> actors;
    std::ifstream sceneFile;
};

#endif // !SCENE_H
