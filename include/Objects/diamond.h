#pragma once
#include "Objects.h"

class diamond: public Objects
{
public:


	diamond(sf::Vector2f pos) : Objects(FileManager::instance().get_icon(DIAMOND), pos, 100) {	};



private :



};
