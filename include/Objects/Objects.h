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

using std::ifstream;
using std::string;

using std::vector;




class Objects
{
public:

	const int SIZE = 60;
	Objects(sf::Vector2f location, int value)
	{
		
		m_sprite.setPosition(location);
		m_value = value;
	
	}

	Objects(sf::Vector2f location)
	{

		m_sprite.setPosition(location);

	}
	
	~Objects() = default;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual int get_value()const = 0;
	
	
protected:
	
	sf::Sprite m_sprite;
	int m_value = 0;


private:
	
	
};
