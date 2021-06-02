#pragma once
#include "Objects.h"

class smallGold : public Objects
{
public:

	smallGold(sf::Vector2f pos) : Objects(pos)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(SMALLGOLD));
		m_sprite.setPosition(pos);
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));
		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });

	}
	~smallGold() {};
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}


	sf::Sprite m_sprite;



};
