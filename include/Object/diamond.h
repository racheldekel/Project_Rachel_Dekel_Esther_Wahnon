#pragma once
#include "Object.h"

class diamond: public Object
{
public:


	diamond(sf::Vector2f pos) : Object(FileManager::instance().getIcon(DIAMOND), pos, 100) {	};
	


private :



};
