#include "Screens/GameOverScreen.h"
#include <iostream>
#include <stdexcept>
class ActionError {};
int GameOverScreen::run(sf::RenderWindow& gold_miner, int &level, int& totalMoney)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;

	int menu = 0;
	if (!Texture.loadFromFile("gameover.jpeg"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	Sprite.scale(1.5f, 1.5f);
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
					if (mouse_button_released(Event))
					{
						level = 0;
						return MENU_SCREEN;

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

		gold_miner.clear();

		gold_miner.draw(Sprite);

		gold_miner.display();
	}

	//Never reaching this point normally, but just in case, exit the gold_minerlication
	return (-1);


}

//-------------------------------------------------------
bool  GameOverScreen::mouse_button_released(sf::Event event)

{

	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x, y);

	//std:: cout << pos.x << " " << pos.y << std::endl;

	if ((pos.x > 415*1.5 && pos.x < 627*1.5) && (pos.y < 425*1.5 && pos.y > 360*1.5))
		return true;

	return false;
}