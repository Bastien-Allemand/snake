#include "SnakeLogics.h"

SnakeLogics::SnakeLogics()
{

}
void SnakeLogics::SnakesFood(float& current_timer_between_move,sf::Vector2f& snakeDirection, std::mt19937& gen,std::vector<sf::Vector2f>& snakeBody,
	sf::Vector2f& foodPosition,bool& found,bool& gameover,float& time_between_move, float& deltaTime)
{
	if (current_timer_between_move <= 0)
	{
		if (snakeDirection.x != 0 || snakeDirection.y != 0) {
			sf::Vector2f nextPosition = snakeBody[0] + snakeDirection;
			if (std::find(snakeBody.begin(), snakeBody.end(), nextPosition) == snakeBody.end()) {
				if (nextPosition == foodPosition) {
					do {
						found = false;
						sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
						if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end() && nextPosition != tmpPosition) {
							found = true;
						}
						foodPosition = tmpPosition;
					} while (found);
					snakeBody.push_back(snakeBody[snakeBody.size() - 1]);
				}
				for (int i = snakeBody.size() - 1; i > 0; --i) {
					snakeBody[i] = snakeBody[i - 1];
				}
				snakeBody[0] = nextPosition;
			}
			else {
				gameover = true;
			}

		}
		current_timer_between_move += (time_between_move - 0.01f * snakeBody.size() < 0.06f) ? 0.06f : (time_between_move - 0.01f * snakeBody.size());
	}
	else
	{
		current_timer_between_move -= deltaTime;
	}
}
