
#include "./engine/engine.h"


const int	WINDOW_WIDTH	= 1024;
const int	WINDOW_HEIGTH	= 768;


int main(int argc, char* args[]) {

	Engine* engine = Engine::instance();

	engine->init( WINDOW_WIDTH, WINDOW_HEIGTH );
	engine->loadScene( "game/level1.json" );

	engine->gameloop();

	engine->close();
	
	return 0;
}








