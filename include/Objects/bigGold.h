#pragma once
#include "Objects.h"

class bigGold : public Objects
{
public:
	
		
	



	bigGold(sf::Vector2f pos, int value) : Objects(pos, m_value)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(BIGGOLD));
		m_sprite.setPosition(pos);
		m_value = m_bigGoldValue;

	}
	~bigGold() {};
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}

	int  get_value() const
	{
		return m_value;
	}

	



	sf::Sprite m_sprite;

private  : 
	

	int m_bigGoldValue = 100;
};
