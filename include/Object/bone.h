#pragma once
#include "Object.h"

class bone : public Object
{
public:
	bone(sf::Vector2f pos) : Object(FileManager::instance().getIcon(BONE), pos, 5) {	};
	


private:



};
