#include "Menu.hpp"

Menu::Menu(void) {
    playing = false;
}

bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp)  {
    if (sprite.contains(mp)) {
        return true;
    }
    return false;
}

int Menu::Run(sf::RenderWindow &App) {
    sf::Event event;
	bool Running = true;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font Font;

    sf::Texture bt1Tex, bt2Tex;
    if (!bt1Tex.loadFromFile("assets/sprites/play.png") || !bt2Tex.loadFromFile("assets/sprites/exit.png")) {
        std::cout << "Had some issue loading buttons" << std::endl;
    }

    sf::Sprite bt1, bt2;
    bt1.setTexture(bt1Tex);
    bt2.setTexture(bt2Tex);
    bt1.setPosition(300, 250);
    bt2.setPosition(300, 420);

    sf::Vector2f mp;

	if (!texture.loadFromFile("assets/sprites/background.png")) {
		std::cerr << "Error loading image" << std::endl;
		return (-1);
	}

	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255));
	if (!Font.loadFromFile("assets/fonts/arial.ttf")) {
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		return (-1);
	}


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
						return 1;
						break;
					default:
						continue;

				}
            }
			
            if(isSpriteHover(bt1.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true) {  
                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {
                    return 1;
                }
            }
			
            if(isSpriteHover(bt2.getGlobalBounds(), sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) == true) {  
                if(event.type == sf::Event::MouseButtonReleased &&  event.mouseButton.button == sf::Mouse::Left) {
                    return (-1);
                }
            }
		}

		App.clear();

        App.draw(sprite);
        App.draw(bt1);
        App.draw(bt2);

		App.display();
    }
    return -1;
}