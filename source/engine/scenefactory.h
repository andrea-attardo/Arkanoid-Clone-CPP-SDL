#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include <string>
#include "scene.h"

class SceneFactory {

public:
    Scene* makeScene( std::string fileName );
     

};


#endif 



