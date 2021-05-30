#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>

class GameScreen : public Screen
{
public:

	GameScreen() {};
	~GameScreen() {};
	
	virtual int run(sf::RenderWindow& gold_miner){ return 1; };


private:
};