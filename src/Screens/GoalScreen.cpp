#include "Screens/GoalScreen.h"
#include <iostream>
#include <stdexcept>

#include <thread>

const auto WAIT_TIME = sf::seconds(4);

class ActionError {};
int  GoalScreen::run(sf::RenderWindow& gold_miner)
{

	//sf::Event Event;
	//bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;

	//while (gold_miner.isOpen())
	//{

	//}
	int menu = 0;

	if (!Texture.loadFromFile("nextGoal.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	Sprite.setTexture(Texture);

	gold_miner.clear();

	gold_miner.draw(Sprite);

	gold_miner.display();

	sf::sleep(WAIT_TIME);


	

	//Never reaching this point normally, but just in case, exit the gold_minerlication
	return (4);


}

//-------------------------------------------------------
bool  GoalScreen::mouse_button_released(sf::Event event)

{

	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x, y);

	std::cout << pos.x << " " << pos.y << std::endl;
	if ((pos.x > 264 && pos.x < 574) && (pos.y < 433 && pos.y > 367))
		return true;

	return false;
}