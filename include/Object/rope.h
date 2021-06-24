#pragma once
#include "Object.h"


const auto MAX_ANGLE= 270.f;
const auto MIN_ANGLE = 90.f;

const auto RIGHT = -1;
const auto LEFT = 1;

class Rope : public Object
{
public:

	Rope(sf::Vector2f pos);
	~Rope() = default;
	void foundObject();
	bool isOpen()const { return m_open; }
	sf::FloatRect getObjectsBounds() const {return m_rect.getGlobalBounds();}
	void openRope(const sf::Time& timePass);
	void rotateRope(const sf::Time& DeltaTime);
	const double  lenghRope = 1;
	void draw(sf::RenderWindow& window);
	void connectToObject(const sf::Time& time);

	void changeState() { m_open = true; }
	void closeRope(sf::Vector2f scale, const sf::Time& time, float LengthAddition);

	const float& getRotation() const;
	
	sf::Vector2f  get_position() const;
	bool getRopeState()const;
	void update_end_rope();
	sf::RectangleShape getRect() { return m_rect; }

	private :

		sf::Vector2f m_scale;
		sf::Sound m_ropeSound;
		sf::Sound m_pullingSound;
		bool  m_closingRope = false;
		bool m_open = false; //true of up or down false if rotate
		void changeDirection();
		sf::Clock m_clock;
		int m_direction = RIGHT;
		bool m_rotate = true;
		bool m_found_object = false;
		sf::RectangleShape m_rect;
		sf::Sprite m_rope_end_sprite;

};
