#pragma once
#include "Objects.h"


class bigRock : public Objects
{
public:

	bigRock(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(BIGROCK), pos, 30) {	};
	~bigRock() {};



private:
	sf::Sprite m_sprite;

};