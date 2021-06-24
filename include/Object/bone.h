#pragma once
#include "Object.h"

class bone : public Object
{
public:
	bone(sf::Vector2f pos) : Object(FileManager::instance().get_icon(BONE), pos, 5) {	};
	


private:



};
