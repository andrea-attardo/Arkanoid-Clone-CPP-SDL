#include "SDL.h"


#ifndef  COMPONENT_H
#define COMPONENT_H

class Component {
public:
	
	virtual void load() = 0;

	virtual void render( SDL_Surface* destsur, SDL_Rect& destrect ) = 0;

	virtual void update() = 0;

};

#endif 
