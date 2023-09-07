#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>
#include "stateManager.hpp"
 
class State {
    public:
 
    StateManager* manager;
 
    virtual void draw(float dt) = 0;
    virtual void update(float dt) = 0;
    virtual void handleInput(float dt) = 0;
};

#endif