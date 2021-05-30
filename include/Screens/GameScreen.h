#pragma once
#include "Screen.h"


class GameScreen : public Screen
{
public:

	GameScreen() {};
	~GameScreen() {};
	
	virtual int run(sf::RenderWindow& gold_miner){};


private:
};