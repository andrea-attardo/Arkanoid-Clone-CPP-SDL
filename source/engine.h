#ifndef ENGINE_H
#define ENGINE_H

#include <vector>


class Engine {
public:
    //Singleton
    static Engine* instance();
   

    //void loadScene();

    //void gameloop();


private:

    Engine();
    static bool isInstantiated;

    //void init();
    //void processEvents();
    //void updateGameLogic( const double deltatime );
    //void render();
    //void close();
   

};





#endif 
