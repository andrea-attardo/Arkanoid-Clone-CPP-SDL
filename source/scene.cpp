#include "scene.h"

Scene::Scene() {}

void Scene::load() {
	for ( auto i : actors ) {
		i.load();
	}
}

void Scene::update( const double deltatime) {
	for ( auto i : actors ) {
		i.update( deltatime );
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
            actor->setW( actorDescr["w"] );
            actor->setH( actorDescr["h"] );

            for ( json compDescr : actorDescr["components"] ) {
                if ( compDescr["type"] == "StaticSpriteComponent" )
                {
                    StaticSpriteComponent* sprite = new StaticSpriteComponent( compDescr["filename"], actor );
                    actor->addComponent( sprite );
                }
                else if ( compDescr["type"] == "BounceMovComponent" )
                {
                    json boundrectDescr = compDescr["boundrect"];
                    BounceMovComponent* bounce = new BounceMovComponent( actor, compDescr, boundrectDescr );
                    actor->addComponent( bounce );
                }

            }

            this->addActor( *actor );

        }

        this->load();
    }

}