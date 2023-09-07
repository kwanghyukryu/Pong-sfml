#pragma once
#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>

class Paddle{
    private:
        sf::RectangleShape m_Shape;
        sf::Vector2f m_Position;
        float m_Speed = 700.0f;

        bool m_MovingLeft = false;
        bool m_MovingRight = false;

    public:
        Paddle(float startX, float startY);

        sf::RectangleShape getShape();
        sf::FloatRect getPosition();

        void moveLeft();
        void moveRight();
        void stopLeft();
        void stopRight();

        void update(sf::Time dt);







};
#endif