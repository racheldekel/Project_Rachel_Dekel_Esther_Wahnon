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
	

	
		sf:: Vector2f getPosition() 
		{
			return m_sprite.getPosition();
		}

		void setPosition(sf:: Vector2f pos) {
			m_sprite.setPosition(pos.x + 1, pos.y + 1);

		}

	
		void move(float passedTime)
		{


			float distance = 120.f * passedTime;

			sf::Vector2f pos = m_sprite.getPosition();
			m_sprite.setPosition(pos*distance);
	
		}

	private:

		sf::Vector2f m_prev_pos;
		int m_mouseValue=2;



};
