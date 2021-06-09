#pragma once
#include "Objects.h"

class bone : public Objects
{
public:
	bone(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(BONE), pos, 5) {	};
	


private:



};
