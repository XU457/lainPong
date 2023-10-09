#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class Paddle {
private:
    sf::Vector2f position;
    sf::RectangleShape paddle_shape;

    float speed;
    bool move_up;
    bool move_down;

    static const unsigned int WIDTH{ 20 };
    static const unsigned int HEIGHT{ 100 }; 

public:
    Paddle(const float x, const float y);
    ~Paddle();

    sf::FloatRect getPosition();
    sf::RectangleShape getShape();

    void moveUp();
    void moveDown();
    void stopUp();
    void stopDown();
    void update(sf::Time& dt);

};  