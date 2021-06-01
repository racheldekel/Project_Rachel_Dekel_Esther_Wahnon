#pragma once
#include "Objects.h"


const int RIGHT = -1;
const int LEFT = 1;
const int MAX_ANGLE= 30;
const int MIN_ANGLE = 330;
class rope : public Objects
{
public:

	rope(sf::Vector2f pos) : Objects(pos)
	{
		m_sprite.setTexture(*(FileManager::instance().get_icon(ROPE)));
		m_sprite.setPosition(pos);
		auto rect = m_sprite.getGlobalBounds();
		m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
			((float)SIZE / rect.height)));
		m_sprite.setOrigin({ rect.width / 2, 0});
		

	}
	~rope() {};

	void openRope(float timePass);
	void rotateRope(float timePass);
	const double  lenghRope = 1;
	void draw(sf::RenderWindow& window);

	
//	sf::Sprite m_sprite;

	private :

		sf::Clock m_clock;
		bool m_open = true;

		//if true it stays the same and we dont open it otherwise we dont change it and we open it 
		void update_state();

		int m_direction = LEFT;


};

