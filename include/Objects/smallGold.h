#pragma once
#include "Objects.h"

class smallGold : public Objects
{
public:

	smallGold(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(SMALLGOLD), pos, 50) {	};
private:

	
};
