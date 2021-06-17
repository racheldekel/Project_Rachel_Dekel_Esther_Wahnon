#include "Screens/StoreScreen.h"
#include <iostream>
#include <stdexcept>

class ActionError {};
int StoreScreen::run(sf::RenderWindow& gold_miner, int& level)
{

	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;

	int menu = 0;


	while (Running)
	{

		m_contol.startStore(gold_miner);


		return;
		//aqui tenemos que poner que devuelva un valor o que se vaya al sigueinte parte del programa o que haga return cuando acabe

	}

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