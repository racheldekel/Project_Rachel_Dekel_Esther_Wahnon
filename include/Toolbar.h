#pragma once
#include <SFML\Graphics.hpp>
#include "FileManager.h"

class Toolbar
{
public:
	Toolbar();
	~Toolbar() {};
	void draw(sf::RenderWindow& window, int level, int money, int goal, int time);



private:
	sf::Text m_ToolbarStatus;
	sf::Text m_ToolbarStatus2;
	sf::Text m_ToolbarStatus3;
	sf::Text m_ToolbarStatus4;

	sf::Font m_font;

};
