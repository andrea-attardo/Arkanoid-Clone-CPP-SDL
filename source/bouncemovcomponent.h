
#ifndef BOUNCEMOVCOMPONENT_H
#define BOUNCEMOVCOMPONENT_H

#include "SDL.h"
#include "actor.h"
#include "component.h"

class BounceMovComponent: public Component {

public:

	BounceMovComponent( Actor* actor );

	void update( const double deltatime );

	void setBoundRect( const int& x, const int& y, const int& w, const int& h );

	void setVx( const double& newvx ) { vx = newvx; }

	void setVy( const double& newvy ) { vy = newvy; }

	double getVx() { return vx; }

	double getVy() { return vy; }


private:
	double vx;
	double vy;
	SDL_Rect boundRect;
	Actor* pActor;
};


#endif 