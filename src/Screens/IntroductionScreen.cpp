#include "Screens/IntroductionScreen.h"
#include <iostream>
#include <stdexcept>
class ActionError {};
int IntroductionScreen::run(sf::RenderWindow& gold_miner)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;

	int menu = 0;
	if (!Texture.loadFromFile("instructions.png"))
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
					if (mouse_button_released(Event))
						return 1;

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
bool IntroductionScreen::mouse_button_released(sf::Event event)

{

	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x, y);

	if ((pos.x > 264 && pos.x < 574) && (pos.y < 433 && pos.y > 367))
		return true;

	return false;
}