#pragma once
#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class ball {
    private:
        sf::Vector2f m_Position;
        sf::CircleShape m_BallShape;


        float m_DirectionX = 1.0f;
        float m_DirectionY = 1.0f;

    public:
        float m_speed = 500;
        ball(float startX,float startY);

        sf::FloatRect getPosition();
        sf::CircleShape getShape();

        float getXVelocity();

        void bounceSides();

        void bounceTop();
        
        void missBottom();

        void hitBall();

        void update(sf::Time dt);









};
#endif