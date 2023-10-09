#pragma once
#include <SFML/Graphics.hpp>

class cScreen {
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};

// This is not a good aproach but using it temprorily
extern int winner;