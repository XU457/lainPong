#pragma once

#include <iostream>
#include "cScreens.hpp"

class Menu : public cScreen {
private:
    bool playing = false;
public:
    Menu(void);
	virtual int Run(sf::RenderWindow &App);
};

