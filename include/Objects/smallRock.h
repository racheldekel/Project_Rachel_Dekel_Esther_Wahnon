#pragma once
#include "Objects.h"

class smallRock: public Objects
{
public:

	smallRock(sf::Vector2f pos, int value) : Objects(pos, m_value)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(SMALLROCK));
		m_sprite.setPosition(pos);
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));
		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });
		m_value = m_smallRockValue;

	}
	~smallRock() {};
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}

	int  get_value()const
	{
		return m_value;
	}
private:
	sf::Sprite m_sprite;
	int m_smallRockValue =15;


};
