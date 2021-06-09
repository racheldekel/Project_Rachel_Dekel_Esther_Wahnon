#pragma once
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include "FileManager.h"
#include <array>
#include <fstream>
#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using std::ifstream;
using std::string;

using std::vector;


const auto SIZE = 60;

class Objects
{
public:

	Objects(sf::Vector2f location)
	{
		m_sprite.setPosition(location);
	
	}
	Objects(const sf::Texture& texture, sf::Vector2f location, int value) : m_sprite(texture)
	{
		m_sprite.setPosition(location);
		m_value = value;
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));

		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });
	
	}

	void draw(sf::RenderWindow& window) const
	{
		window.draw(m_sprite);
	}
	
	
	~Objects() = default;
	int get_value() const
	{
		return m_value;
	};

	bool intersects(const sf::FloatRect& rect)
	{
		auto objectLock = m_sprite.getGlobalBounds();
		return rect.intersects(m_sprite.getGlobalBounds());
	}



	
protected:
	
	sf::Sprite m_sprite;
	int m_value = 0;



private:
	
	
};
