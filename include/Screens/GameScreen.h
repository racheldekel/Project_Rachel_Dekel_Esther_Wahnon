#pragma once
#include "Screen.h"

class GameScreen : Screen
{
public:

	GameScreen() {};
	~GameScreen() {};
	int run(sf::RenderWindow& gold_miner) override;


private:
};