#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class GoalScreen : public Screen
{
public:

	GoalScreen() {};
	~GoalScreen() {};
	virtual int run(sf::RenderWindow& gold_miner) ;
	bool mouse_button_released(sf::Event event);


private:
};