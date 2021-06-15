#include "Screens/GameScreen.h"
#include <iostream>
#include <stdexcept>
class ActionError {};
int GameScreen::run(sf::RenderWindow& gold_miner, int& level)
{

	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;

	
	
	if (!Texture.loadFromFile("background.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}

	Sprite.setTexture(Texture);
	Sprite.scale(1.5f, 1.5f);



	while (Running)
	{
		//Verifying events
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

					break;

				case sf::Event::KeyPressed:
					throw ActionError();

					break;

				}

				auto number = m_controller.startGame(gold_miner);

				if (number == EXIT)
				{
					level= 0;
					return START_SCREEN;
					
				}

				if (number == TIME_OVER)
				{
					level = 0;
					return GAME_OVER_SCREEN;
				}

				if (m_controller.getLevel() <= NUM_OF_LEVELS)
				{
					return GOAL_SCREEN;

				}



				
			}
			catch (ActionError)
			{
				std::cout << "Please click the mouse" << std::endl;

			}

		}
		
		gold_miner.clear();

		gold_miner.draw(Sprite);

		gold_miner.display();
	}

	//Never reaching this point normally
	return (-1);


}
