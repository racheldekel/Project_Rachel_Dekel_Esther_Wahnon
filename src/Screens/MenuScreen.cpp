#include "Screens/MenuScreen.h"
#include <iostream>
#include <stdexcept>
class ActionError {};
int MenuScreen::run(sf::RenderWindow& gold_miner, int& level, int& totalMoney)
{

	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	int alpha = 0;
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	int menu = 0;

	if (!Texture.loadFromFile("menu.jpg"))
	{
		std::cerr << "Error loading file" << std::endl;
		return (-1);
	}

	//Sprite.scale( 1, 1);
	Sprite.setTexture(Texture);
	

	while (Running)
	{
		
		while (gold_miner.pollEvent(Event))
		{
			try
			{
				switch (Event.type)
				{
				case sf::Event::Closed:
					return -1;
					break;


				case sf::Event::MouseButtonReleased:
					if (button_released_in_introduction(Event))
						return INTRODUCTION_SCREEN;

					else if (button_released_start_game(Event))
					{
						return GOAL_SCREEN;
					}
					break;

				case sf::Event::KeyPressed:
					throw ActionError();

					break;

				}
			}
			catch (ActionError& de)
			{
				std::cout << "Please click the mouse" << std::endl;

			}

		}
		



		//Clearing screen
		gold_miner.clear();
		//Drawing
		gold_miner.draw(Sprite);

		gold_miner.display();
	}

	//Never reaching this point normally, but just in case, exit the gold_minerlication
	return (-1);


}

//-------------------------------------------------------
bool MenuScreen ::button_released_in_introduction(sf::Event event)

{

	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x, y);


	if ((pos.x > 106 && pos.x < 540) && (pos.y < 367 && pos.y > 276))
		return true;

	return false;
}
//-----------------------------------------------------------------------------
bool MenuScreen::button_released_start_game(sf::Event event)
{

	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x, y);

	
	if ((pos.x > 696 && pos.x < 868) && (pos.y < 252 && pos.y > 90))
		return true;

	return false;

}