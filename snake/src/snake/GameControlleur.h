#pragma once
#include "SFML/Graphics.hpp"
class GameControlleur
{
public:
	GameControlleur();
	sf::Vector2f checkMovement(sf::Event event);

};

