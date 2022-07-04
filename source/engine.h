#ifndef ENGINE_H
#define ENGINE_H

#include <vector>


class Engine {
public:
    //Singleton
    static Engine* instance();
   
    void init( const int windw, const int windh );

    void loadScene( std::string filename );

    void gameloop();


private:

    Engine();
    static bool isInstantiated;

    SDL_Window* window = NULL;
    SDL_Surface* windowSurface = NULL;
    
    //void processEvents();
    //void updateGameLogic( const double deltatime );
    //void render();
    //void close();
   

};





#endif 
