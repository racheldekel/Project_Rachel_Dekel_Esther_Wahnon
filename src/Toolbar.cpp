#include "Toolbar.h"


Toolbar::Toolbar()
{
	m_font = *(FileManager::instance().getFont(0));
	m_ToolbarStatus.setFont(m_font);
	m_ToolbarStatus2.setFont(m_font);
	m_ToolbarStatus3.setFont(m_font);
	m_ToolbarStatus4.setFont(m_font);

}

void Toolbar::draw(sf::RenderWindow& window, int level,int money, int goal, int time)
{

	std::string moneys = "Money " + std::to_string(money);

	m_ToolbarStatus.setPosition(100, 10);
	m_ToolbarStatus.setString(moneys);
	m_ToolbarStatus.setColor(sf::Color::Magenta);
	m_ToolbarStatus.setCharacterSize(20);

	std::string goals= " Goal " + std::to_string(goal);
	m_ToolbarStatus2.setPosition(100, 30);
	m_ToolbarStatus2.setString(goals);
	m_ToolbarStatus2.setColor(sf::Color::Magenta);
	m_ToolbarStatus2.setCharacterSize(20);



	std::string times = "Time  " + std::to_string(time);

	m_ToolbarStatus3.setPosition(630, 10);
	m_ToolbarStatus3.setString(times);
	m_ToolbarStatus3.setColor(sf::Color::Magenta);
	m_ToolbarStatus3.setCharacterSize(20);


	std::string levels = "Level " + std::to_string(level);

	m_ToolbarStatus4.setPosition(630, 30);
	m_ToolbarStatus4.setString(levels);
	m_ToolbarStatus4.setColor(sf::Color::Magenta);
	m_ToolbarStatus4.setCharacterSize(20);

	

	window.draw(m_ToolbarStatus);
	window.draw(m_ToolbarStatus2);
	window.draw(m_ToolbarStatus3);
	window.draw(m_ToolbarStatus4);

}