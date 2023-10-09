#pragma once
#include "cScreens.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Paddle.hpp"
#include "Ball.hpp"

class Game: public cScreen {
private:
    bool playing;
public:
    Game(void);
    virtual int Run(sf::RenderWindow &App);
};
