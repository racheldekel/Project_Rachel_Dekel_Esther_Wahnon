#pragma once
#include "Objects.h"

class bone : public Objects
{
public:

	bone(sf::Vector2f pos, int value) : Objects(pos, m_value)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(BONE));
		m_sprite.setPosition(pos);
		m_value = m_boneValue;
	}

	~bone() {};
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}

	int  get_value() const
	{
		return m_value;
	}
	sf::Sprite m_sprite;
private:
	int m_boneValue =5;


};
