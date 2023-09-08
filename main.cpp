#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.cpp"
#include "Paddle.cpp"
#include <sstream>


int main() {

    sf::VideoMode VM(1000, 720);
    sf::RenderWindow window(VM,"pong");
    sf::Clock clock;
    ball myball(1000/2,0);
    Paddle myPaddle(450,710);

    sf::Font font;
    font.loadFromFile("Roboto-Regular.ttf");
    sf::Text fontHUD;
    fontHUD.setFont(font);
    fontHUD.setPosition(5,0);
    fontHUD.setCharacterSize(30);
    fontHUD.setOutlineThickness(1);
    fontHUD.setOutlineColor(sf::Color::White);
    fontHUD.setFillColor(sf::Color::Green);

    sf::Text fontDead;
    fontDead.setFont(font);
    fontDead.setPosition(280,720/2);
    fontDead.setCharacterSize(40);
    fontDead.setOutlineThickness(1);
    fontDead.setOutlineColor(sf::Color::White);
    fontDead.setFillColor(sf::Color::Red);

    sf::Text fontPoint;
    fontPoint.setFont(font);
    fontPoint.setPosition(870,0);
    fontPoint.setCharacterSize(30);
    fontPoint.setOutlineThickness(1);
    fontPoint.setOutlineColor(sf::Color::White);
    fontPoint.setFillColor(sf::Color::Blue);

    int lives = 3;
    std::stringstream ss;
    ss << "Lives:" << lives;
    fontHUD.setString(ss.str());

    int point = 0;
    std::stringstream pp;
    pp << "points:" << point;
    fontPoint.setString(pp.str());

    sf::Time dt;
    sf::Event event;

    float bounceTimer = 0.10f;
  
    while (window.isOpen()){
        dt = clock.restart();
        bounceTimer -= dt.asSeconds();

        if (myball.getPosition().intersects(myPaddle.getPosition())){
            if (bounceTimer<0){
                myball.hitBall();
                bounceTimer = 0.10f;
                myball.m_speed += 5;
                point++;
                pp.str("");
                pp << "Point:" << point;
                fontPoint.setString(pp.str());
            }
        }

        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            myPaddle.moveLeft();
        }

        else{
            myPaddle.stopLeft();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            myPaddle.moveRight();
        }

        else{
            myPaddle.stopRight();
        }

        if (myball.getPosition().left < 0 || myball.getPosition().left + myball.getPosition().width > 1000){
            myball.bounceSides();
        }
        if (myball.getPosition().top <0 && bounceTimer<0){
            myball.bounceTop();
            bounceTimer = 0.10f;
        }
        if (myball.getPosition().top+myball.getPosition().height>720){
            myball.missBottom();
            lives--;
            myball.m_speed = 500;
            ss.str("");
            ss << "Lives:" << lives;
            fontHUD.setString(ss.str());
            

        }

        if (lives == 0){
            std::stringstream aa;
            aa << "press esc to exit the game";
            fontDead.setString(aa.str());
            myball.m_speed = 0;

        }

        

        window.clear();
        myball.update(dt);
        myPaddle.update(dt);


        window.draw(myball.getShape());
        window.draw(myPaddle.getShape());
        window.draw(fontHUD);
        window.draw(fontDead);
        window.draw(fontPoint);
        window.display();

    }

    return 0;
} 
//g++ main.cpp $(pkg-config --libs --cflags sfml-window sfml-system sfml-graphics) -o main; ./main

