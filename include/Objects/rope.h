#pragma once
#include "Objects.h"



const auto MAX_ANGLE= 270.f;
const auto MIN_ANGLE = 90.f;

const auto RIGHT = -1;
const auto LEFT = 1;

class rope : public Objects
{
public:

	rope(sf::Vector2f pos);
	~rope() = default;

	void openRope(float timePass);
	void rotateRope(float timePass);
	const double  lenghRope = 1;
	void draw(sf::RenderWindow& window);

	
//	sf::Sprite m_sprite;

	private :

		sf::Clock m_clock;
		bool m_open = false;
		void changeDirection();
		//if true it stays the same and we dont open it otherwise we dont change it and we open it 
		void update_state();

		int m_direction = RIGHT;
		
		


};
