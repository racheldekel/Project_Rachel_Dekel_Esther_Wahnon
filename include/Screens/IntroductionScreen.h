#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class IntroductionScreen : public Screen
{
public:
	IntroductionScreen() {};
	~IntroductionScreen() {};
	virtual int run(sf::RenderWindow& gold_miner) { return 1; };


private:
};