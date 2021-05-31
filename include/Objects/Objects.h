#pragma once
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include "FileManager.h"
#include <array>

using std::vector;



//enum Direction_t { UP, RIGHT, DOWN, LEFT };

class Objects
{
public:

	
	Objects(sf::Vector2f location) 
	{
		m_sprite.setPosition(location);
	}
	
		~Objects() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	
	

protected:


	sf::Sprite m_sprite;

private:
	
};
