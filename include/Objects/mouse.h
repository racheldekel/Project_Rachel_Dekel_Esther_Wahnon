#pragma once
#include <SFML\Graphics.hpp>
#include "FileManager.h"


#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;
class Mouse: public Objects
{
public:

	Mouse(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(MOUSE), pos, 2) {	};
	
	void move(sf::Vector2f boardSize);

	

	
	sf:: Vector2f getPosition() {
		return m_sprite.getPosition();
	}

	void setPosition(sf:: Vector2f pos) {
		m_sprite.setPosition(pos.x + 10, pos.y + 10);

	}

	
	void move(float passedTime)
	{


		float distance = 120.f * passedTime;

		//std::cout << distance;
		sf::Vector2f pos = m_sprite.getPosition();
		m_sprite.setPosition(pos.x + 10, pos.y +10);
		//m_sprite.move(distance, 0);
	//m_pos = m_sprite.getPosition();
	}

protected:


private:

	sf::Vector2f m_prev_pos;
	int m_mouseValue=2;
	enum  Direction { RIGHT, LEFT };

	Direction  m_current_direction;

	sf::Sprite m_sprite;



	//Direction m_arr[];

};
