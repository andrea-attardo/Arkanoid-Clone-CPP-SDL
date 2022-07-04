#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "SDL.h"
#include "scene.h"

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

    

private:

    Engine();
    static bool     isInstantiated;

    SDL_Window*     window;
    SDL_Surface*    windowSurface;
    SDL_Event		Event;
    bool			quit;
       
    Scene*          scene;

    double oldtime;
    double newtime;
    double deltatime;
};





#endif 
