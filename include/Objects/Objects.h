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
	Objects(sf::Vector2f location) 
	{
		
		m_sprite.setPosition(location);
	
	}
	
	~Objects() {};
	virtual void draw(sf::RenderWindow& window) = 0;
	
protected:
	
	sf::Sprite m_sprite;



private:
	
};
