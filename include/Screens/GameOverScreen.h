#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class GameOverScreen : public Screen
{
public:

	GameOverScreen() {};
	~GameOverScreen() {};
	virtual int run(sf::RenderWindow& gold_miner) { return 1; };


private:
};