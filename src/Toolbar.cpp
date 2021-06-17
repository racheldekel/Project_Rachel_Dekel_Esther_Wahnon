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

	std::string moneys =  std::to_string(money);

	m_ToolbarStatus.setPosition(165, 15);
	m_ToolbarStatus.setString(moneys);
	m_ToolbarStatus.setColor(sf::Color::Black);
	m_ToolbarStatus.setCharacterSize(30);

	std::string goals=  std::to_string(goal);
	m_ToolbarStatus2.setPosition(162, 50);
	m_ToolbarStatus2.setString(goals);
	m_ToolbarStatus2.setColor(sf::Color:: Black);
	m_ToolbarStatus2.setCharacterSize(30);



	std::string times = std::to_string(time);

	m_ToolbarStatus3.setPosition(946, 60);
	m_ToolbarStatus3.setString(times);
	m_ToolbarStatus3.setColor(sf::Color :: Black);
	m_ToolbarStatus3.setCharacterSize(30);


	std::string levels = std::to_string(level);

	m_ToolbarStatus4.setPosition(950, 15);
	m_ToolbarStatus4.setString(levels);
	m_ToolbarStatus4.setColor(sf::Color::Black);
	m_ToolbarStatus4.setCharacterSize(30);

	

	window.draw(m_ToolbarStatus);
	window.draw(m_ToolbarStatus2);
	window.draw(m_ToolbarStatus3);
	window.draw(m_ToolbarStatus4);

}
//---------------------------------------------------------------------------------------------------------------
void Toolbar::draw_money(sf::RenderWindow& window,  int money)
{

	
	std::string moneys = "AMOUNT OF MONEY " + std::to_string(money);


	m_ToolbarStatus.setPosition(30, 15);
	m_ToolbarStatus.setString(moneys);
	m_ToolbarStatus.setColor(sf::Color::Black);
	m_ToolbarStatus.setCharacterSize(35);
	m_ToolbarStatus.getOutlineThickness( );
	window.draw(m_ToolbarStatus);

}

