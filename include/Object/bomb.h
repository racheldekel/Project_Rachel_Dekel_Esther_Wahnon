#pragma once
#include "Object.h"

class bomb: public Object
{
public:

	bomb(sf::Vector2f pos) : Object(FileManager::instance().getIcon(BOMB), pos, 0) {	};

};
