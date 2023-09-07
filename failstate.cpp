#include <SFML/Graphics.hpp>
#include "failstate.hpp"

#include <iostream>

FailState::FailState(StateManager* sman) {
    manager = sman;

    sf::Vector2f pos = sf::Vector2f(manager->window.getSize());
    view.setSize(pos);
    pos *= 0.5f;
    view.setCenter(pos);

    failmsg.setString("game failed to load, press Escape to close");
    failmsg.setFillColor(sf::Color::White);
    failmsg.setCharacterSize(60);

     if (!font.loadFromFile("Roboto-Regular.ttf")) {
        std::cout << "failed to load font";
    }


    failmsg.setFont(font);
    
    pos -= failmsg.getGlobalBounds().getSize() * 0.5f;
    failmsg.setPosition(pos);
}

FailState::~FailState() {

    manager = nullptr;
    delete manager;
}

void FailState::draw(float dt)
{
    manager->window.setView(view);
    manager->window.clear(sf::Color::Black);
    manager->window.draw(failmsg);
 
    return;
}

void FailState::update(float dt) {
    return;
}

void FailState::handleInput(float dt) {
    sf::Event event;
    while (manager->window.pollEvent(event)){

            switch(event.type){
                case sf::Event::Closed: 
                    manager->window.close();
                    break;

                case sf::Event::Resized:
                    view = letterBox(view, event.size.width, event.size.height);
                    break;               

                default:
                    break;
            }
        }

   return;
}

sf::View FailState::letterBox(sf::View view, int windowWidth, int windowHeight){

    float windowRatio = windowWidth / (float) windowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    }

    else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );

    return view;   
}