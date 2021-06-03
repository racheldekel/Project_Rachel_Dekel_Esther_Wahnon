#include "Screens/GoalScreen.h"
#include <iostream>
#include <stdexcept>

#include <thread>

const auto WAIT_TIME = sf::seconds(4);

class ActionError {};
int  GoalScreen::run(sf::RenderWindow& gold_miner)
{

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

