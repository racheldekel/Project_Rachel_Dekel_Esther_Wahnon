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
	int alpha = 0;
	sf::Font Font;

	int menu = 0;

	if (!Texture.loadFromFile("instructions.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	Sprite.setTexture(Texture);



	if (!Font.loadFromFile("Font1.otf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		return (-1);
	}

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
						return 2;

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
		//When getting at alpha_max, we stop modifying the sprite




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

	std::cout << pos.x << " " << pos.y << std::endl;
	if ((pos.x > 353 && pos.x < 466) && (pos.y < 338 && pos.y > 246))
		return true;

	return false;
}