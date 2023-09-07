#ifndef FAILSTATE_H
#define FAILSTATE_H
#include <SFML/Graphics.hpp>
#include "state.hpp"

class FailState : public State {
    private:

        sf::View view;
        sf::Text failmsg;
        sf::Font font;
        

    public:

        FailState(StateManager* manager);
        ~FailState();

        virtual void draw(float dt);
        virtual void update(float dt);
        virtual void handleInput(float dt);

        sf::View letterBox(sf::View, int, int);
};

#endif