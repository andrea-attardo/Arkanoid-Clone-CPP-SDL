#include "scene.h"

Scene::Scene() {}

void Scene::load() {
	for ( auto i : actors ) {
		i.load();
	}
}

void Scene::update() {
	for ( auto i : actors ) {
		i.update();
	}
}

void Scene::render( SDL_Surface* destsur ) {
	for ( auto i : actors ) {
		i.render( destsur );
	}
}

void Scene::addActor( Actor actor ) {
	actors.push_back( actor );
}

void Scene::loadSceneFromFile( std::string fileName ) {

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
                    BounceMovComponent* bounce = new BounceMovComponent( actor );
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