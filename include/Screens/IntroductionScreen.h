#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class IntroductionScreen : public Screen
{
public:
	IntroductionScreen() {};
	~IntroductionScreen() {};
	virtual int run(sf::RenderWindow& gold_miner, int& level, int& totalMoney) ;
	bool mouse_button_released(sf::Event event);


private:
};