#include "Objects/rope.h"


const auto SPEED = 0.5f;
//-----------------------------------------------------------

//------------------------------------------------------------------------------
void Rope :: update_end_rope()
{
	auto height = m_sprite.getLocalBounds().height * m_sprite.getScale().y;

	auto new_y_pos = m_sprite.getPosition().y + height;
}
//-----------------------------------------------------------------------------
void Rope::changeDirection()
{
	m_direction = (m_direction == 1) ? -1 : 1;
}
//--------------------------------------------------------------------------------
Rope::Rope(sf::Vector2f pos) : Objects(pos)
{
	m_sprite.setTexture(FileManager::instance().get_icon(ROPE));
	m_sprite.setPosition(pos);
	auto rect = m_sprite.getGlobalBounds();
	m_sprite.setScale(sf::Vector2f(((float)60 / rect.height),
		((float)60 / rect.height)));
	m_sprite.setOrigin({ rect.width / 2, 0 });
	

}
//------------------------------------------------------------
sf:: Vector2f  Rope::get_position() const
{
	return m_sprite.getPosition();//+ m_scale;
}

//----------------------------------------------------------
const float& Rope::getRotation() const
{
	return m_sprite.getRotation();
}
//---------------------------------------------------------------------
bool Rope ::getRopeState()
{
	return m_rotate ;
}
//------------------------------------------------------------------
void Rope::connectToObject(const sf::Time& time)
 {
	m_scale = m_sprite.getScale();

	

		float LengthAddition = Rope::lenghRope *0.2; //* time.asSeconds();

		m_scale.y += LengthAddition;

		m_sprite.setScale(m_scale);

}
//----------------------------------------------------------------------
void Rope::openRope(const sf::Time& time )
{
	m_rotate = false;

	m_scale = m_sprite.getScale();

	// to open the rope 
	if (m_scale.y < 2.80 &&  !m_closingRope )
	{
		
		float LengthAddition = Rope::lenghRope * time.asSeconds(); //* time.asSeconds();

		m_scale.y += LengthAddition;

		m_sprite.setScale(m_scale);

		if (m_scale.y > 2.7 || m_found_object)
			m_closingRope = true;

	}

	// here we still have to work on changing according to the object 
	 if (m_closingRope )
	{
		 if (!m_found_object) // in case that the rope closes w/o any objects 
		 {
			 float LengthAddition = Rope::lenghRope * time.asSeconds()*5.f; //* time.asSeconds();
			 closeRope(m_scale, time, LengthAddition);
		 }

		 else {
			 // here we have to calculate according to each object that has caught
			 float LengthAddition = Rope::lenghRope * time.asSeconds(); //* time.asSeconds();
			 closeRope(m_scale, time, LengthAddition);

			 }
	}

	
}
//----------------------------------------------
void Rope:: foundObject()
{
	m_found_object = true;
}
//-------------------------------------------------------------------------------------------
void Rope :: closeRope(sf :: Vector2f scale, const sf::Time& time, float LengthAddition)
{
	
	m_rotate = false;
	m_scale.y -= LengthAddition;

	m_sprite.setScale(m_scale);

	if (m_scale.y < 0.65)
	{
		m_closingRope = false;
		m_open = false;
		return;
	}
}
//----------------------------------------------------------------------------------------------
void Rope::draw(sf::RenderWindow& window)
{

	window.draw(m_sprite);
}
//-------------------------------------------------------------------------------------------------
void Rope::rotateRope(const sf::Time& DeltaTime)
{
	m_found_object = false;
	m_rotate = true;
	if (m_sprite.getRotation() > MIN_ANGLE && m_sprite.getRotation() < MAX_ANGLE)
	{
		changeDirection();
	}
	//std::cout << m_direction << std::endl;
	//std::cout << timePass << std::endl;
	auto angle = /*DeltaTime.asSeconds() **/ m_direction * SPEED;
	m_sprite.rotate(angle);
}

