#include "SDL.h"


#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:

	virtual void load() {};

	virtual void update( const double deltatime ) {};

	virtual void render( SDL_Surface* destsur ) {};

	virtual void keyAction( SDL_Scancode keypressed ) {};

};

#endif 
