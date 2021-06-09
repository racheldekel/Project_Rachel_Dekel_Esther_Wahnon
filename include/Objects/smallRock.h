#pragma once
#include "Objects.h"

class smallRock: public Objects
{
public:


	smallRock(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(SMALLROCK), pos, 15) {	};
	
private:



};
