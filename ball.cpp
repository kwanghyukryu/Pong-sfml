#include "ball.hpp"

ball::ball(float startX, float startY){

    m_Position.x = startX;
    m_Position.y = startY;

    m_BallShape.setRadius(10);
    m_BallShape.setPosition(m_Position);

}

sf::FloatRect ball::getPosition(){
    return m_BallShape.getGlobalBounds();

}

sf::CircleShape ball::getShape(){
    return m_BallShape;
}

float ball::getXVelocity(){
    return m_DirectionX;
}

void ball::bounceSides(){
    m_DirectionX = -m_DirectionX;
}

void ball::bounceTop(){
    m_DirectionY = -m_DirectionY;
}

void ball::missBottom(){
    m_Position.x = 1000/2;
    m_Position.y = 0;
}

void ball::update(sf::Time dt){
    m_Position.x += m_DirectionX*m_speed*dt.asSeconds();
    m_Position.y += m_DirectionY*m_speed*dt.asSeconds();

    m_BallShape.setPosition(m_Position);
    
}

void ball::hitBall(){
    m_DirectionY = -m_DirectionY;
}