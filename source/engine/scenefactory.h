#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H


#include "scene.h"

class SceneFactory {

public:
    Scene* makeScene( std::string fileName );
     

};


#endif 



