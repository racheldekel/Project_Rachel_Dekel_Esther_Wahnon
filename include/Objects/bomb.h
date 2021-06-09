#pragma once
#include "Objects.h"

class bomb: public Objects
{
public:

	bomb(sf::Vector2f pos, int value ) : Objects(pos, m_value)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(BOMB));
		m_sprite.setPosition(pos);
	}
	~bomb() {};
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}
	int  get_value()const
	{
		return m_value;
	}

	sf::Sprite m_sprite;



};
