#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class LevelScreen : public Screen
{
public:

	LevelScreen() {};
	~LevelScreen() {};
	virtual int run(sf::RenderWindow& gold_miner) ;


private:
};