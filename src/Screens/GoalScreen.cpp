#include "Screens/GoalScreen.h"
#include <iostream>
#include <stdexcept>

#include <thread>

const auto WAIT_TIME = sf::seconds(3);

class ActionError {};
int  GoalScreen::run(sf::RenderWindow& gold_miner)
{

	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;


	int menu = 0;

	if (!Texture.loadFromFile("nextGoal.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	Sprite.setTexture(Texture);

	
	gold_miner.clear();
	sf::Font font;
	font.loadFromFile("gameFont.otf");

	auto number  = m_goalScreen[i];
	sf::Text text(std::to_string(number), font);
	i++;
	text.setCharacterSize(40);
	text.setStyle(sf::Text::Bold);
	text.setPosition(380, 230);
	text.setFillColor(sf::Color ::Yellow);
	gold_miner.draw(Sprite);
	gold_miner.draw(text);

	gold_miner.display();
	sf::sleep(WAIT_TIME);
	
	


	

	return GAME_SCREEN;


}

