#pragma once
#include "Objects.h"

class bomb: public Objects
{
public:

	bomb(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(BOMB), pos, 0) {	};

};
