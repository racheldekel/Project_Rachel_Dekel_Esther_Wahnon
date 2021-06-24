#pragma once
#include "Object.h"

class diamond: public Object
{
public:


	diamond(sf::Vector2f pos) : Object(FileManager::instance().get_icon(DIAMOND), pos, 100) {	};
	


private :



};
