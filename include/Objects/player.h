#pragma once
#include "Objects.h"

class Player : public Objects
{
public:



	Player(sf::Vector2f pos) : Objects(pos)
	{
		m_sprite.setTexture(FileManager::instance().get_icon(PLAYER));
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)60/ rect.height),
			((float)60/ rect.height)));
		m_sprite.setOrigin({ rect.width / 2, rect.height/ 2 });


	}

};

/*Objects(sf::Vector2f location)
	{
		m_sprite.setPosition(location);
	}

	~Objects() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	*/