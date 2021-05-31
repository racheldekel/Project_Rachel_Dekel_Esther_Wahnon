#include "Screens/GameScreen.h"
#include <iostream>
#include <stdexcept>
class ActionError {};
int GameScreen::run(sf::RenderWindow& gold_miner)
{

	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;

	int menu = 0;

	if (!Texture.loadFromFile("background.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	Sprite.setTexture(Texture);



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

				m_controller.startGame(gold_miner);

				if (m_controller.getLevel() <= NUM_OF_LEVELS)
				{
					return 3;

				}


				//else we have to print the end of the game 
					//break;

				
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
