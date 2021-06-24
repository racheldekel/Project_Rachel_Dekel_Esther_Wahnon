#pragma once
#include "Object.h"

class bomb: public Object
{
public:

	bomb(sf::Vector2f pos) : Object(FileManager::instance().get_icon(BOMB), pos, 0) {	};

};
