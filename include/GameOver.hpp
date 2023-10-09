#pragma once

#include <iostream>
#include "cScreens.hpp"

class GameOver : public cScreen {
private:
    bool playing = false;
public:
    GameOver(void);
	virtual int Run(sf::RenderWindow &App);
};
