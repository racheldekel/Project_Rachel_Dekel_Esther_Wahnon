#pragma once
#include "Objects.h"

class diamond: public Objects
{
public:

	diamond(sf::Vector2f pos) : Objects(pos)
	{
		m_sprite.setTexture(*(FileManager::instance().getIconTexture(DIAMOND)));
		m_sprite.setPosition(pos);
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));
		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });

	}

	~diamond() {};
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}


	sf::Sprite m_sprite;



};
