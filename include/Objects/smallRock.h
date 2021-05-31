#pragma once
#include "Objects.h"

class smallRock: public Objects
{
public:

	smallRock(sf::Vector2f pos) : Objects(pos)
	{
		m_sprite.setTexture(*(FileManager::instance().getIconTexture(SMALLROCK)));
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f());
		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });


	}
	void draw(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}


	sf::Sprite m_sprite;



};