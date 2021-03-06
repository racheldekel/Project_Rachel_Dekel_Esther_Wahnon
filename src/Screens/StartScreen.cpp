#include "Screens/StartScreen.h"
#include <iostream>
#include <stdexcept>


int StartScreen ::run(sf::RenderWindow& gold_miner, int& level, int& totalMoney)
{
	
	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	int alpha = 0;
	sf::Font Font;
	
	int menu = 0;

	if (!Texture.loadFromFile("startGame.jpg"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	//Sprite.scale(1.5, 1.52);
	Sprite.setTexture(Texture);
	
	
	while (Running)
	{
		level = 0;
		//Verifying events
		while (gold_miner.pollEvent(Event))
		{
				switch (Event.type)
				{
				case sf::Event::Closed:
					return -1;
					break;
				case sf::Event::MouseButtonReleased:
					if (mouse_button_released(Event))
						
						return MENU_SCREEN;
					
					break;

				

				}
			
			
		}
		

		gold_miner.clear();
		
		gold_miner.draw(Sprite);
		
		gold_miner.display();
	}

	return (-1);
	

}

//-------------------------------------------------------
bool StartScreen::mouse_button_released(sf::Event event)

{

	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x, y);

	if ((pos.x > 409 && pos.x < 814) && (pos.y < 647 && pos.y > 535))
		return true;

	return false;
}