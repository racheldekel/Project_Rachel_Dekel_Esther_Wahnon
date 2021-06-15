#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class StartScreen : public Screen
{
public:

	StartScreen() {};
	~StartScreen() {};
	virtual int run(sf::RenderWindow& gold_miner, int& level) ;

	bool mouse_button_released(sf::Event event);
private:
};
