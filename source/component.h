#include "SDL.h"


#ifndef  COMPONENT_H
#define COMPONENT_H

class Component {
public:

	virtual void load() {};

	virtual void render( SDL_Surface* destsur, SDL_Rect& destrect ) {};

	virtual void update() {};

};

#endif 
