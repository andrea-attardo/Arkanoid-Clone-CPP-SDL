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

void Scene::sceneFactory( std::string fileName ) {

    sceneFile.open( fileName );
    if ( sceneFile.fail() ) {
        std::cerr << ( "Error in " + fileName );
    }
    else
    {

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

            }

            this->addActor( *actor );

        }

        this->load();
    }

}