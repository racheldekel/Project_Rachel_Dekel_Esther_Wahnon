#pragma once
#include "Objects.h"


class bigGold : public Objects
{
public:
	bigGold(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(BIGGOLD), pos, 100){	};
private  : 
	

	
};
