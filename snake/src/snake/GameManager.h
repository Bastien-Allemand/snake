#pragma once
#include "SFML/Graphics.hpp"
#include "random"
#include "GameControlleur.h"
#include "SnakeLogics.h"
class GameManager
{
public:
	GameManager(GameControlleur gc, std::mt19937 gen);

};

