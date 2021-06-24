#pragma once
#include "Object.h"


class bigGold : public Object
{
public:
	bigGold(sf::Vector2f pos) : Object(FileManager::instance().get_icon(BIGGOLD), pos, 100){	};
private  : 
	

	
};
