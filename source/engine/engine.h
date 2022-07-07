#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "SDL.h"
#include "scene.h"
#include "inputsystem.h"
#include "collisionsysytem.h"

class Engine {
public:

    //Singleton
    static Engine* instance();
   
    void init( const int windw, const int windh );

    void loadScene( std::string filename );

    void gameloop();

    void processEvents();
    void update();
    void render();

    void close();

    InputSystem*     getInputsys() { return &inputsys; }
    //CollisionSystem* getCollisionsys() { return collisionsys; }
  
private:

    Engine();
    static Engine*  pEngine;
    static bool     isInstantiated;

    SDL_Window*     window;
    SDL_Surface*    windowSurface;

    Scene*          scene;
    
    InputSystem     inputsys;
    //CollisionSystem* collisionsys;

    SDL_Event		Event;
    bool			quit;

    double          oldtime;
    double          newtime;
    double          deltatime;

};


#endif 
