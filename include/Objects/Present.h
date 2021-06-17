#pragma once
#include "Objects.h"

class Present : public Objects
{
public:
	Present(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(PRESENT), pos, 100) {	};

	
private:


};
//---------------------------------------------------------------------------------------------------------------------


