#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class MenuScreen : public  Screen
{
public:

	MenuScreen() {};
	~MenuScreen() {};
	
	virtual int run(sf::RenderWindow& gold_miner, int& level) ;

	bool button_released_in_introduction(sf::Event event);

	bool button_released_start_game(sf::Event event);


private:
};