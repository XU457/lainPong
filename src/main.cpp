#include "ScreenStack.hpp"

int main(int argc, char **argv) {

	Menu menu;
	Game game;
	GameOver gameOver;

	std::vector<cScreen*> Screens;
	int screen = 0;

	sf::RenderWindow App(sf::VideoMode(800, 600), "Lain Pong");	

	Screens.push_back(&menu);
	Screens.push_back(&game);
	Screens.push_back(&gameOver);

	while (screen >= 0) {
		screen = Screens[screen]->Run(App);
	}

	return 0;
}
