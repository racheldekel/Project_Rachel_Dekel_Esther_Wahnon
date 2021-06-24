#pragma once
#include "Object.h"

class Present : public Object
{
public:
	Present(sf::Vector2f pos) : Object(FileManager::instance().get_icon(PRESENT), pos, 100) {	};

private:

};
//---------------------------------------------------------------------------------------------------------------------


