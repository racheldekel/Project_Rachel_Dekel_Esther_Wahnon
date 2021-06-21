#include "Screens/GameScreen.h"
#include <iostream>
#include <stdexcept>
class ActionError {};
int GameScreen::run(sf::RenderWindow& gold_miner, int& level, int& totalMoney)
{


	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;


	while (Running)
	{
		//Verifying events
		while (1)
		{
				auto number = m_controller.startGame(gold_miner, totalMoney, level );

				if (number == EXIT)
				{
					totalMoney = 0;
					level= 0;
					return START_SCREEN;
					
				}

				if (number == TIME_OVER)
				{
					totalMoney = 0;
					level = 0;
					return GAME_OVER_SCREEN;
				}

				if (m_controller.getLevel() <= NUM_OF_LEVELS)
				{
					return STORE_SCREEN;
					

				}

				else 
					return GAME_OVER_SCREEN;

		}
		
		gold_miner.clear();

		gold_miner.draw(Sprite);

		gold_miner.display();
	}

	//Never reaching this point normally
	return (-1);


}
