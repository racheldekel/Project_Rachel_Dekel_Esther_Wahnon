#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class StartScreen : public Screen
{
public:

	StartScreen() {};
	~StartScreen() {};
	virtual int run(sf::RenderWindow& gold_miner) ;


private:
};
