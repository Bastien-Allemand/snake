#include "GameControlleur.h"

GameControlleur::GameControlleur()
{

}

sf::Vector2f GameControlleur::checkMovement(sf::Event event)
{
	if (event.key.scancode == sf::Keyboard::Scancode::Left) {
		return sf::Vector2f(-1, 0);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Right) {
		return sf::Vector2f(1, 0);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Up) {
		return sf::Vector2f(0, -1);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Down) {
		return sf::Vector2f(0, 1);
	}
}
