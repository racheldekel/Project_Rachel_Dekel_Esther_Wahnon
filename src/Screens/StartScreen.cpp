#include "Screens/StartScreen.h"
#include <iostream>
#include <stdexcept>
class ActionError {};
int StartScreen ::run(sf::RenderWindow& gold_miner)
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

	if (!Texture.loadFromFile("startScreen.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	Sprite.setTexture(Texture);
	//Sprite.setColor(sf::Color(255, 255, 255, alpha));


	if (!Font.loadFromFile("Font1.otf"))
	{
		std::cerr << "Error loading verdanab.ttf" << std::endl;
		return (-1);
	}
	Menu1.setFont(Font);
	Menu1.setCharacterSize(40);
	Menu1.setString("Play");
	Menu1.setPosition({ 280.f, 160.f });

	Menu2.setFont(Font);
	Menu2.setCharacterSize(40);
	Menu2.setString("Exit");
	Menu2.setPosition({ 280.f, 220.f });

	Menu3.setFont(Font);
	Menu3.setCharacterSize(50);
	Menu3.setString("Continue");
	Menu3.setPosition({ 280.f, 160.f });

	
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

				//case sf::Event::KeyPressed:
					//throw ActionError();

				}
			}
			catch (ActionError& de)
			{
				std::cout << "Please click the mouse" << std::endl;

			}
			
		}
		//When getting at alpha_max, we stop modifying the sprite
		
		
		

		//Clearing screen
		//gold_miner.clear();
		//Drawing
		gold_miner.draw(Sprite);
		
		gold_miner.display();
	}

	//Never reaching this point normally, but just in case, exit the gold_minerlication
	return (-1);
	

}

//-------------------------------------------------------
bool StartScreen::mouse_button_released(sf::Event event)

{

	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x , y );

	std::cout << pos.x << " " << pos.y << std::endl;
	if ((pos.x > 353 && pos.x < 466) && (pos.y < 338 && pos.y > 246))
		return true;

	return false;
}