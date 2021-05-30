#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class MenuScreen : public  Screen
{
public:

	MenuScreen() {};
	~MenuScreen() {};
	
	virtual int run(sf::RenderWindow& gold_miner) { return 1; };


private:
};