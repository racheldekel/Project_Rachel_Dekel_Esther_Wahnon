#pragma once
#include "Object.h"

class smallRock: public Object
{
public:


	smallRock(sf::Vector2f pos) : Object(FileManager::instance().get_icon(SMALLROCK), pos, 15) {	};
	
private:



};
