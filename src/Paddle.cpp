#include "Paddle.hpp"

Paddle::Paddle(const float x, const float y)
    : position {x, y}
    , speed { 1000.f }
    , move_up { false }
    , move_down { false } {
    paddle_shape.setSize(sf::Vector2f(WIDTH, HEIGHT));
    paddle_shape.setPosition(position);
    paddle_shape.setFillColor(sf::Color::White);
}

Paddle::~Paddle() { }

sf::FloatRect Paddle::getPosition() {
    return paddle_shape.getGlobalBounds();
}

sf::RectangleShape Paddle::getShape() {
    return paddle_shape;
}

void Paddle::moveUp() {
    move_up = true;
}

void Paddle::moveDown() {
    move_down = true;
}

void Paddle::stopUp() {
    move_up = false;
}

void Paddle::stopDown() {
    move_down = false;
}

void Paddle::update(sf::Time& dt) {
    if (move_up) {
        position.y -= speed * dt.asSeconds();
    }
    if (move_down) {
        position.y += speed * dt.asSeconds();
    }
    paddle_shape.setPosition(position);
}