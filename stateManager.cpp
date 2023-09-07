#include <SFML/Graphics.hpp>
#include <stack>
#include "state.hpp"
#include "stateManager.hpp"

StateManager::StateManager(int resX, int resY) {
    window.create(sf::VideoMode(resX ,resY), "Pong");
    window.setFramerateLimit(240);
}

StateManager::~StateManager() {
    while(!states.empty()) {
        popState();
    }
}


void StateManager::pushState(State* state) {
    states.push(state);
    return;
}

void StateManager::popState() {
    delete states.top();
    states.pop();
    return;
}

void StateManager::changeState(State* state) {
    if(!states.empty()){
        popState();
    }

    pushState(state);
    return;
}

State* StateManager::getState() {
    if(states.empty()) {
        return nullptr;
        }
    return states.top();
}

