#include "Screens/MenuScreen.h"
#include <iostream>
#include <stdexcept>
class ActionError {};
int MenuScreen::run(sf::RenderWindow& gold_miner, int& level)
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

	if (!Texture.loadFromFile("menu_final.jpg"))
	{
		std::cerr << "Error loading file" << std::endl;
		return (-1);
	}

	Sprite.scale(1.5, 1.5);
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

	
	if ((pos.x > 90 && pos.x < 480) && (pos.y < 570 && pos.y > 480))
		return true;

	return false;
}
//-----------------------------------------------------------------------------
bool MenuScreen::button_released_start_game(sf::Event event)
{

	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x, y);

	
	if ((pos.x > 120 && pos.x < 450) && (pos.y < 300 && pos.y > 27))
		return true;

	return false;

}