#pragma once
#include "Object.h"


class bigRock : public Object
{
public:

	bigRock(sf::Vector2f pos) : Object(FileManager::instance().getIcon(BIGROCK), pos, 30) {	};
	~bigRock() {};



private:
	sf::Sprite m_sprite;

};