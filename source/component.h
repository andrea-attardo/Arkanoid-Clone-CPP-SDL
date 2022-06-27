#include "SDL.h"


#ifndef  COMPONENT_H
#define COMPONENT_H

class Component {
public:

	virtual void load() {};

	virtual void render( SDL_Surface* destsur ) {};

	virtual void update() {};

};

#endif 
