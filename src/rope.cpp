#include "Objects/rope.h"


const auto SPEED = 0.5f;
//-----------------------------------------------------------
void Rope::update_state(const sf::Time& timePass)
{


	if (m_open)
		openRope(timePass);

	else
		rotateRope(timePass);
	

}
void Rope::changeDirection()
{
	m_direction = (m_direction == 1) ? -1 : 1;
}
Rope::Rope(sf::Vector2f pos) : Objects(pos)
{
	m_sprite.setTexture(FileManager::instance().get_icon(ROPE));
	m_sprite.setPosition(pos);
	auto rect = m_sprite.getGlobalBounds();
	m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
		((float)SIZE / rect.height)));
	m_sprite.setOrigin({ rect.width / 2, 0 });
	

}
//------------------------------------------------------------
int  Rope :: get_value() const
{
	return m_value;
}
//----------------------------------------------------------------------
void Rope::openRope(const sf::Time& time )
{
	
	int x, y;

	sf::Vector2i pos;

	
	auto scale = m_sprite.getScale();

	std::cout << scale.x << " " << scale.y << std::endl;


	// to open the rope 
	if (scale.y < 2.80 &&  !m_closingRope && !m_isAttach)
	{
		
		float LengthAddition = Rope::lenghRope * time.asSeconds(); //* time.asSeconds();

		scale.y += LengthAddition;

		m_sprite.setScale(scale);

		if (scale.y > 2.7)
			m_closingRope = true;

		// collision

		//m_isAttach = true ;
		
	}

	// close the rope 
	 if (m_closingRope )
	{
		 if (!m_isAttach) // in case that the rope closes w/o any objects 
		 {
			 float LengthAddition = Rope::lenghRope * time.asSeconds(); //* time.asSeconds();
			 closeRope(scale, time, LengthAddition);
		 }

		 else {
			 // here we have to calculate according to each object that has caught
			 float LengthAddition = Rope::lenghRope * time.asSeconds(); //* time.asSeconds();
			 closeRope(scale, time, LengthAddition);

			 }
	}

	
}
//-------------------------------------------------------------------------------------------
void Rope :: closeRope(sf :: Vector2f scale, const sf::Time& time, float LengthAddition)
{
	

	scale.y -= LengthAddition;

	m_sprite.setScale(scale);

	if (scale.y < 0.65)
	{
		m_closingRope = false;
		m_open = false;
		return;
	}
}
//----------------------------------------------------------------------------------------------
void Rope::draw(sf::RenderWindow& window)
{

	update_state();

	//window.clear();
	window.draw(m_sprite);
}
//-------------------------------------------------------------------------------------------------
void Rope::rotateRope(const sf::Time& DeltaTime)
{
	if (m_sprite.getRotation() > MIN_ANGLE && m_sprite.getRotation() < MAX_ANGLE)
	{
		changeDirection();
	}
	//std::cout << m_direction << std::endl;
	//std::cout << timePass << std::endl;
	auto angle = /*DeltaTime.asSeconds() **/ m_direction * SPEED;
	std::cout << angle << std::endl;
	m_sprite.rotate(angle);
}

