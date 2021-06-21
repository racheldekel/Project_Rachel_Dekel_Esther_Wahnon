#pragma once
#include <SFML\Graphics.hpp>
#include "FileManager.h"


#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;
class Mouse : public Objects
{
public:

	Mouse(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(MOUSE), pos, 2) {	};

	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void move(float passedTime);

private:

	sf::Vector2f m_prev_pos;
	int m_mouseValue = 2;

};
