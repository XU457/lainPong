#include "GameOver.hpp"

GameOver::GameOver(void) {
    playing = false;
}

int GameOver::Run(sf::RenderWindow &App) {
    sf::Event event;
    sf::Texture texture;
	sf::Sprite sprite;
	bool Running = true;
	sf::Font font;

	if (!font.loadFromFile("assets/fonts/arial.ttf")) {
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		return (-1);
	}

    if (!texture.loadFromFile("assets/sprites/gameOver.jpg")) {
		std::cerr << "Error loading image" << std::endl;
		return (-1);
	}
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255));
    sprite.setPosition(100, 120);

    int playerLost = winner;
    int playerWon = (winner == 1) ? 2 : 1;

    sf::Text winner("Winner is:- Player " + std::to_string(playerWon) + ".", font, 30);
    winner.setPosition(250, 300);
    winner.setFillColor(sf::Color::Blue);

    sf::Text looser("Looser is:- Player " + std::to_string(playerLost) + ".", font, 30);
    looser.setPosition(250, 380);
    looser.setFillColor(sf::Color::Red);
    
    while (Running) {
		while (App.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				return (-1);
			}

            if (event.type == sf::Event::KeyPressed) {

				switch (event.key.code) {
					case sf::Keyboard::Escape:
						App.close();
                        return -1;
						break;
					case sf::Keyboard::Return:
						return -1;
						break;
					default:
						continue;

				}
            }
		}

		App.clear();

        App.draw(sprite);
        App.draw(winner);
        App.draw(looser);

		App.display();
    }
    return -1;
}