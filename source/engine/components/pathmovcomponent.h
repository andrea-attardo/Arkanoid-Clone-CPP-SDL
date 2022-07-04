#ifndef PATHMOVCOMPONENT_H
#define PATHMOVCOMPONENT_H

#include <array>
#include <vector>
#include "SDL.h"
#include "actor.h"
#include "component.h"
#include "json.hpp"
using json = nlohmann::json;

class PathMovComponenet: public Component {
public:

    PathMovComponenet( Actor* actor, json pathDescr );
    
    void update( const double deltatime );

private:
    std::vector<std::array<double, 3>> path;
    Actor* pActor;
    
    
    int nextleg;
    double nextlegX;
    double nextlegY;
    double nextlegTime;
    double distanceXs;
    double distanceYs;
    double vx;
    double vy;
};

#endif