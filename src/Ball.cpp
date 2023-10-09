#include "Ball.hpp"

Ball::Ball(const float x, const float y)
    : position {x, y}
    , speed { 300.f }
    , direction_x  { 1.5f }
    , direction_y { 0.5f } {
    ball_shape.setRadius(RADIUS);
    ball_shape.setPosition(position);
    ball_shape.setFillColor(sf::Color::White);
}

Ball::~Ball() { }

sf::FloatRect Ball::getPosition() {
    return ball_shape.getGlobalBounds();
}

sf::CircleShape Ball::getShape() {
    return ball_shape;
}

void Ball::setPositionX(const float xPos) {
    position.x = xPos;
}

void Ball::setPositionY(const float yPos) {
    position.y = yPos;
}

void Ball::reboudPaddle() {
    direction_x = -direction_x;
}

void Ball::reboundToporBottom() {
    direction_y = -direction_y;
}

void Ball::update(sf::Time& dt) {
    position.x += direction_x * speed * dt.asSeconds();
    position.y += direction_y * speed * dt.asSeconds();

    ball_shape.setPosition(position);
}