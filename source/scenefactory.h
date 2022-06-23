#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include <iostream>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

class SceneFactory{
public:
    SceneFactory() {}

    void loadSceneFromFile( std::string fileName ) {
        
        try {
            sceneFile.open( fileName );
            if ( sceneFile.fail() ) {
                throw std::runtime_error( "Error in " + fileName);
            }

            sceneFile >> sceneDescriptor;

            //std::cout << sceneDescriptor["window"];

        }
        catch ( std::runtime_error& err ) {
            std::cout << err.what() << std::endl;
        }

    }
    
private:
    std::ifstream sceneFile;
    json sceneDescriptor;
};


#endif // !SCENEFACTORY_H
