#pragma once
#include "Objects.h"

class player : public Objects
{
public:

	player(sf::Vector2f pos) : Objects(pos)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(PLAYER));
		m_sprite.setPosition(pos);
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));
		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });
	}
	~player() {};
	void draw(sf::RenderWindow& window)
		{
			window.draw(m_sprite);
		}
	

	sf::Sprite m_sprite;



};

/*Objects(sf::Vector2f location)
	{
		m_sprite.setPosition(location);
	}

	~Objects() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	*/