#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class GoalScreen : public Screen
{
public:

	GoalScreen() {};
	~GoalScreen() {};
	virtual int run(sf::RenderWindow& gold_miner, int& level) ;



private:
	
	int m_goalScreen[6] =  { 300, 500, 800, 1100, 1400, 1700 };
};