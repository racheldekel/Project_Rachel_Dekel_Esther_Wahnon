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


	bool isOpen()const { return m_open; }
	sf::FloatRect get_objects_bounds() const
	{
		return m_sprite.getGlobalBounds();
	}
	void openRope(const sf::Time& timePass);
	void rotateRope(const sf::Time& DeltaTime);
	const double  lenghRope = 1;
	void draw(sf::RenderWindow& window);
	
	void changeState() { m_open = true; }
	void closeRope(sf::Vector2f scale, const sf::Time& time, float LengthAddition);

		const float& getRotation() const;
	int  get_value()const;
	sf::Vector2f  get_position() const;
	bool getRopeState();
	void update_end_rope();
	private :
		sf::Vector2f m_scale;
		bool m_isAttach = false;
		bool  m_closingRope = false;
		bool m_open = false; //true of up or down false if rotate
		void changeDirection();
		//if true it stays the same and we dont open it otherwise we dont change it and we open it 
		
		sf::Clock m_clock;
		int m_direction = RIGHT;
		bool m_rotate = true;
		
		sf::Sprite m_rope_end_sprite;

};
