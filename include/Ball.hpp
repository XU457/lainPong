#pragma once
#include <SFML/Graphics.hpp>

class Ball {
private:
    sf::Vector2f position;
    sf::CircleShape ball_shape;

    float speed, direction_x, direction_y; // Velocity
    static const unsigned int RADIUS { 10 };

public:
    Ball(const float x, const float y);
    ~Ball();

    sf::FloatRect getPosition();
    sf::CircleShape getShape();

    void setPositionX(const float xPos);
    void setPositionY(const float yPos);

    // Collision
    void reboudPaddle();
    void reboundToporBottom();

    void update(sf::Time& dt);

};