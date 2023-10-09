#include "Game.hpp"

int winner;

Game::Game(void) {
    playing = false;
}

int Game::Run(sf::RenderWindow &App) {
    bool running = true;
    
    int rightScore = 0, leftScore = 0;
    
    Paddle leftPaddle(50, 250);
	Paddle rightPaddle(730, 250);

    Ball ball(390, 290);

	sf::Event event;
	float paddleSpeed = 5.0f;

	// Load Sound
	sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("assets/music/collision.wav"))
        return EXIT_FAILURE;

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(30.f);

	sf::Vector2 ballSpeed(0.1f, 0.1f);

	sf::Clock clock;

    sf::Music music;
    if (!music.openFromFile("assets/music/background_music.mp3")) {
        std::cerr << "Error while loading background music file" << std::endl;
        return -1;
    }
    music.setVolume(10.f);
    music.play();

    sf::Font font;
    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cout << "Got some error with font load" << std::endl;
        return -1;
    }

    while (running) {
        while (App.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				App.close();
			}

			if (event.type == sf::Event::KeyPressed) {

				switch (event.key.code) {
					case sf::Keyboard::Escape:
						App.close();
                        return -1;
						break;
					case sf::Keyboard::W:
						leftPaddle.moveUp();
						break;
					case sf::Keyboard::S:
						leftPaddle.moveDown();
						break;
					case sf::Keyboard::Up:
						rightPaddle.moveUp();
						break;
					case sf::Keyboard::Down:
						rightPaddle.moveDown();
						break;
					default:
						continue;

				}
			}
			
			if (event.type == sf::Event::KeyReleased) {

				switch (event.key.code) {
					case sf::Keyboard::W:
						leftPaddle.stopUp();
						break;
						break;
					case sf::Keyboard::S:
						leftPaddle.stopDown();
						break;
					case sf::Keyboard::Up:
						rightPaddle.stopUp();
						break;
					case sf::Keyboard::Down:
						rightPaddle.stopDown();
						break;
					default:
						continue;

				}
			}
		}

		sf::Time dt = clock.restart();

		rightPaddle.update(dt);
		leftPaddle.update(dt);
		ball.update(dt);

		if (ball.getPosition().intersects(leftPaddle.getPosition()) ||
			ball.getPosition().intersects(rightPaddle.getPosition())) {
			sound.play();
			ball.reboudPaddle();
		}

		if (ball.getPosition().top < 0 || ball.getPosition().top > 600) {
			ball.reboundToporBottom();
        }

		if (ball.getPosition().left < 0) {
			rightScore += 1;
			ball.setPositionX(390);
			ball.setPositionY(290);
			ball.reboudPaddle();
		} else if (ball.getPosition().left > 800) {
			leftScore += 1;
			ball.setPositionX(390);
			ball.setPositionY(290);
			ball.reboudPaddle();
		}

        sf::Text leftScoreText(std::to_string(leftScore), font, 50);
        leftScoreText.setPosition(300, 10);
        leftScoreText.setFillColor(sf::Color::White);

        sf::Text player1("P1", font, 50);
        player1.setPosition(50, 10);
        player1.setFillColor(sf::Color::Blue);

        sf::Text rightScoreText(std::to_string(rightScore), font, 50);
        rightScoreText.setPosition(450, 10);
        rightScoreText.setFillColor(sf::Color::White);

        sf::Text player2("P2", font, 50);
        player2.setPosition(700, 10);
        player2.setFillColor(sf::Color::Red);

        if(music.getStatus() != sf::Music::Status::Playing)
            music.play();

		App.clear(sf::Color::Black);

        App.draw(leftScoreText);
        App.draw(player1);
        App.draw(rightScoreText);
        App.draw(player2);
		App.draw(leftPaddle.getShape());
		App.draw(rightPaddle.getShape());
		App.draw(ball.getShape());

		App.display();

		if (leftScore >= 5 || rightScore >= 5) {
            leftScore = 0;
            rightScore = 0;
            winner = (leftScore > rightScore) ? 1 : 2;
            return 2;
        }
    }

    return -1;
}
