#pragma once
#include "Object.h"

class smallGold : public Object
{
public:

	smallGold(sf::Vector2f pos) : Object(FileManager::instance().get_icon(SMALLGOLD), pos, 50) {	};
private:

	
};
