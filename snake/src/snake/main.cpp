#include <SFML/Graphics.hpp>
#include <random>
#include "GameControlleur.h"
#include "GameManager.h"
#include <iostream>

int main()
{
	std::mt19937 gen;
	gen.seed(time(nullptr));
	GameControlleur gc;
	GameManager gm(gc,gen);
	return 0;
}



