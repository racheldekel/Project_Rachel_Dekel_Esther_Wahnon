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

	
	Objects(sf::Vector2f location, int value)
	{
		m_sprite.setPosition(location);
		m_value = value;
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));
		//m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });
	
	}

	Objects(sf::Vector2f location)
	{

		m_sprite.setPosition(location);
		/*auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));
		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });
		*/
	}
	
	~Objects() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual int get_value()const = 0;

	bool intersects(const sf::FloatRect& rect)
	{
		auto objectLock = m_sprite.getGlobalBounds();
		return rect.intersects(m_sprite.getGlobalBounds());
	}



	/*
	bool intersects(Objects* other) {
		if (other == nullptr) {
			return false;
		}
	//	std::cout << m_sprite.getGlobalBounds().height << std::endl;
		return m_sprite.getGlobalBounds().intersects(other->m_sprite.getGlobalBounds());
	}*/
	
	
protected:
	
	sf::RectangleShape m_object;
	sf::Sprite m_sprite;
	int m_value = 0;



private:
	
	
};
