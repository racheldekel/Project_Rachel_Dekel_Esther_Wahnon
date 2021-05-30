#pragma once
#include "Screen.h"

class IntroductionScreen : Screen
{
public:
	IntroductionScreen() {};
	~IntroductionScreen() {};
	int run(sf::RenderWindow& gold_miner) override;


private:
};