#include "Screens/StoreScreen.h"
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class ActionError {};
int StoreScreen::run(sf::RenderWindow& gold_miner, int& level)
{

	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;

	int menu = 0;


	srand(time(NULL));


	auto num = rand() % 2;

		if (num==0)
		m_contol.startStore(gold_miner);

		return GOAL_SCREEN;

	

	return (-1);
}
//-----------------------------------------------------------------------------------------------------------------
bool StoreScreen::mouse_button_released(sf::Event event)
{

	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x, y);

//	std::cout << pos.x << " " << pos.y << std::endl;
	//if ((pos.x > 409 && pos.x < 814) && (pos.y < 647 && pos.y > 535))
		//return true;

	return false;
}
//--------------------------------------------------------------