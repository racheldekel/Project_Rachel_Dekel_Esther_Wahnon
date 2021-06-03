#pragma once
#include "Objects.h"



const auto MAX_ANGLE= 270.f;
const auto MIN_ANGLE = 90.f;

const auto RIGHT = -1;
const auto LEFT = 1;

class Rope : public Objects
{
public:

	Rope(sf::Vector2f pos);
	~Rope() = default;

	void openRope(const sf::Time& timePass);
	void rotateRope(const sf::Time& DeltaTime);
	const double  lenghRope = 1;
	void draw(sf::RenderWindow& window);
	void update_state(const sf::Time& timePass = sf::Time());

	
//	sf::Sprite m_sprite;

	private :

		bool m_open = false; //true of up or down false if rotate
		void changeDirection();
		//if true it stays the same and we dont open it otherwise we dont change it and we open it 

		sf::Clock m_clock;
		int m_direction = RIGHT;
		
		


};
