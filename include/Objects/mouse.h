#pragma once
#include <SFML\Graphics.hpp>
#include "FileManager.h"


#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;
class Mouse: public Objects
{
public:
	
	void move(sf::Vector2f boardSize);

	

	Mouse(sf::Vector2f pos,int  value) : Objects(pos, m_value)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(MOUSE));
		m_sprite.setPosition(pos);
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));
		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });;
		m_value = m_mouseValue;
	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}
	int  get_value() const
	{
		return m_value;
	}


	


protected:


private:

	sf::Vector2f m_prev_pos;
	int m_mouseValue=2;
	enum  Direction { RIGHT, LEFT };

	Direction  m_current_direction;

	sf::Sprite m_sprite;



	//Direction m_arr[];

};
