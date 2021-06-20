#include "Screens/GoalScreen.h"
#include <iostream>
#include <stdexcept>

#include <thread>

const auto WAIT_TIME = sf::seconds(3);

class ActionError {};
int  GoalScreen::run(sf::RenderWindow& gold_miner, int& level, int& totalMoney)
{

	m_nextLevelSound.setBuffer(FileManager::instance().getSound(FINISHLEVEL_s));
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;

	std::cout << level;
	if (!Texture.loadFromFile("nextGoal.png"))
	{
		std::cerr << "Error loading presentation.gif" << std::endl;
		return (-1);
	}
	Sprite.scale(1.5, 1.5);
	Sprite.setTexture(Texture);
	m_nextLevelSound.play();

	
	gold_miner.clear();
	sf::Font font;
	font.loadFromFile("gameFont.otf");
	auto number  = m_goalScreen[level];
	 level++;
	sf::Text text(std::to_string(number), font);
	text.setCharacterSize(60);
	text.setStyle(sf::Text::Bold);
	text.setPosition(570, 345);
	text.setFillColor(sf::Color ::Yellow);
	gold_miner.draw(Sprite);
	gold_miner.draw(text);

	gold_miner.display();
	sf::sleep(WAIT_TIME);

	return GAME_SCREEN;


}

