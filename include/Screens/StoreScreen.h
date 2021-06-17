#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Controller.h"
class StoreScreen : public Screen
{
public:

	StoreScreen() {};
	~StoreScreen() {};
	virtual int run(sf::RenderWindow& gold_miner, int& level);
	bool mouse_button_released(sf::Event event);
private:


	Controller m_contol;
};

