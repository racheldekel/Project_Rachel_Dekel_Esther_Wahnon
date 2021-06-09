#pragma once
#include "Objects.h"

class diamond: public Objects
{
public:

	diamond(sf::Vector2f pos, int value) : Objects(pos, m_diamondValue)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(DIAMOND));
		m_sprite.setPosition(pos);
		m_value = m_diamondValue;
	}

	~diamond() {};
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}
	int  get_value() const
	{
		return m_value;
	}

	sf::Sprite m_sprite;


	//int price = 100;


private :

	int m_diamondValue=100;


};
