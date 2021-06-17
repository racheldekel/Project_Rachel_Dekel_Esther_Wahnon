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


const auto SIZE = 40.f;

class Objects
{
public:
	
	Objects(const sf::Texture& texture, sf::Vector2f location, int value) : m_sprite(texture)
	{
		m_sprite.setPosition(location);
		m_value = value;
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height*1.5),
			((float)SIZE / rect.height*1.5)));

		m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });

	}
	//---------------------------------------------------------------------------

	void setAngle(float angle)
	{
		m_angle = angle;
	}
	//----------------------------------------------------------------------------------------
	float getAngle()const
	{ 
		return  m_angle;
	}
	//----------------------------------------------------------------------------------------
	sf::Vector2f getPosition() 
	{

		return m_sprite.getPosition();
	}

	//_-------------------------------------------------------------------
	Objects(sf::Vector2f location)
	{
		m_sprite.setPosition(location);

	}
	~Objects() = default;
	void draw(sf::RenderWindow& window) const;
	void  moveMouse() ;
	int get_value() const;
	bool  moveObject(const sf::Time& timePass, sf::Vector2f posRope, float angle);
	bool is_intersected( sf::FloatRect& rect);
	void MakeBigger();
protected:
	
	sf::Sprite m_sprite;
	int m_value = 0;



private:
	
	float m_angle;
	bool m_mouseMoveRight = true;
};
