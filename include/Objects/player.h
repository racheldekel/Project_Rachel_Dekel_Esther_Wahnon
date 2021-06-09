#pragma once
#include "Objects.h"

class Player : public Objects
{
public:

	Player(sf::Vector2f pos) : Objects(pos)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(PLAYER));
		m_sprite.setPosition(pos);
		auto rect = m_sprite.getGlobalBounds();
		
		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });
	}
	void draw(sf::RenderWindow& window)
		{
			window.draw(m_sprite);
		}
	

	virtual int  get_value() const override { return 0; };
	sf::Sprite m_sprite;



};

/*Objects(sf::Vector2f location)
	{
		m_sprite.setPosition(location);
	}

	~Objects() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	*/