#pragma once
#include "SFML/Graphics.hpp"
#include <random>
class SnakeLogics
{
public:
	SnakeLogics();
	void SnakesFood(float& current_timer_between_move, sf::Vector2f& snakeDirection, std::mt19937& gen, std::vector<sf::Vector2f>& snakeBody,
		sf::Vector2f& foodPosition, bool& found, bool& gameover, float& time_between_move, float& deltaTime);
};

