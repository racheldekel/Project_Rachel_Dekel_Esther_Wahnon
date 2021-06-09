#pragma once
#include "Objects.h"

class bigRock: public Objects
{
public:

	bigRock(sf::Vector2f pos,int  value) : Objects(pos, m_value)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(BIGROCK));
		m_sprite.setPosition(pos);
		/*auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));
		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });
		auto rect2 = m_sprite.getGlobalBounds();*/
		m_value = m_bigRockValue;

	}
	~bigRock() {};
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}

	int  get_value() const
	{
		return m_value;
	}
private:
	sf::Sprite m_sprite;

	int m_bigRockValue=30;

};
