#ifndef HELLOSDL_H
#define HELLOSDL_H

#include "sdl.h"

void init();
bool loadMedia();
void close();
void processEvents();
SDL_Surface* loadSurface( const char* path );


#endif // !HELLOSDL_H
