#include "GameManager.h"

GameManager::GameManager(GameControlleur gc, std::mt19937 gen)
{
	SnakeLogics sl;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");

	sf::RectangleShape shape(sf::Vector2f(32, 32));

	std::vector<sf::Vector2f> snakeBody;
	snakeBody.push_back(sf::Vector2f(0, 0));
	sf::Vector2f snakeDirection(0, 0);

	sf::Vector2f foodPosition;
	bool found;
	do {
		found = false;
		sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
		if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end()) {
			found = true;
		}
		foodPosition = tmpPosition;
	} while (found);


	sf::View v = window.getDefaultView();
	v.setCenter(0, 0);

	window.setView(v);


	float time_between_move = 0.5f;
	float current_timer_between_move = 0.f;

	bool gameover = false;

	sf::Clock c;
	// run the program as long as the window is open
	while (window.isOpen())
	{
		float deltaTime = c.restart().asSeconds();
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				snakeDirection = gc.checkMovement(event);
			}
		}

		window.clear(sf::Color::Black);
		if (gameover) {

		}
		else
		{
			sl.SnakesFood(current_timer_between_move, snakeDirection, gen, snakeBody, foodPosition, found, gameover, time_between_move, deltaTime);
			for (sf::Vector2f p : snakeBody) {
				shape.setPosition(p * shape.getSize().x);
				shape.setFillColor(sf::Color::Green);
				window.draw(shape);
			}

			shape.setPosition(foodPosition * shape.getSize().x);
			shape.setFillColor(sf::Color::Red);
			window.draw(shape);
		}

		window.display();
	}
}
