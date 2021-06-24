#pragma once
#include "Object.h"

class Player : public Object
{
public:



	Player(sf::Vector2f pos) : Object(pos)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(PLAYER));
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)60 / rect.height)*1.8,
			((float)60 / rect.height)*1.8));
		m_sprite.setOrigin({ rect.width / 2, rect.height/ 2 });


	}
	void playerStand()
	{
		m_sprite.setTexture(FileManager::instance().get_icon(PLAYER));
	}
	void playerGrab()
	{
		m_sprite.setTexture(FileManager::instance().get_icon(PLAYERGRAB));
	}
	void setScale(int x, int y)
	{
		m_sprite.setScale(x, y);
	}
};

