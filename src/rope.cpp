#include "Object/rope.h"
const auto SPEED = 0.5f;
//-----------------------------------------------------------------------------
void Rope::changeDirection()
{
	m_direction = (m_direction == 1) ? -1 : 1;
}
//--------------------------------------------------------------------------------
Rope::Rope(sf::Vector2f pos) : Object(pos)
{
	m_sprite.setTexture(FileManager::instance().getIcon(ROPE));
	m_sprite.setPosition(pos);
	auto rect = m_sprite.getGlobalBounds();
	m_sprite.setScale(sf::Vector2f(((float)60 / rect.height) * 1.5,
		((float)60 / rect.height) * 1.5));

	m_sprite.setOrigin({ rect.width / 2, 0 });
}
//------------------------------------------------------------
sf:: Vector2f  Rope::getPosition() const
{
	return m_sprite.getPosition();
}
//----------------------------------------------------------
const float& Rope::getRotation() const
{
	return m_sprite.getRotation();
}
//---------------------------------------------------------------------
bool Rope ::getRopeState()const
{
	return m_rotate ;
}
//------------------------------------------------------------------
void Rope::connectToObject(const sf::Time& time)
 {
	m_scale = m_sprite.getScale();

		float LengthAddition = Rope::lenghRope *0.2; 

		m_scale.y += LengthAddition;

		m_sprite.setScale(m_scale);
}
//-------------------------------------------------------------------------------
//opening the rope 
void Rope::openRope(const sf::Time& time )
{
	m_rotate = false;
	m_ropeSound.setBuffer(FileManager::instance().getSound(ROPE_s));
	m_pullingSound.setBuffer(FileManager::instance().getSound(PULLING_s));
	m_scale = m_sprite.getScale();

	// to open the rope 
	if (m_scale.y < 4.5 &&  !m_closingRope )
	{
		float LengthAddition = Rope::lenghRope * time.asSeconds()*4.4f;
		m_scale.y += LengthAddition;
		m_sprite.setScale(m_scale);
		m_ropeSound.play();
			if (m_scale.y > 4.35|| m_found_object)
				m_closingRope = true;
	}

	 if (m_closingRope )
	 {
		 if (!m_found_object) // in case that the rope closes w/o any Object 
		 {
			 float LengthAddition = Rope::lenghRope * time.asSeconds()*6.f; 
			 closeRope(m_scale, time, LengthAddition);
		 }

		 else 
		 {
			
			 // here we have to calculate according to each object that has caught
			 float LengthAddition = Rope::lenghRope * time.asSeconds() * 4.45f; //* time.asSeconds();
			 closeRope(m_scale, time, LengthAddition);
			 m_pullingSound.play();
		 }
	 }
}
//--------------------------------------------------------------------------------------------------
void Rope:: foundObject()
{
	m_found_object = true;
}
//-------------------------------------------------------------------------------------------
//in case that we have to close the rope
void Rope :: closeRope(sf :: Vector2f scale, const sf::Time& time, float LengthAddition)
{
	m_rotate = false;
	m_scale.y -= LengthAddition;

	m_sprite.setScale(m_scale);

	if (m_scale.y < 0.825)
	{
		m_closingRope = false;
		m_open = false;
		return;
	}
}
//----------------------------------------------------------------------------------------------
void Rope::draw(sf::RenderWindow& window)
{
	auto rect = m_sprite.getGlobalBounds();
	auto pos = m_sprite.getPosition();
	auto angle2 = m_sprite.getRotation();
	auto angle = m_direction * SPEED;
	m_rect.setSize(sf::Vector2f(0.5, 0.5));


	//the m_rect helps us to get the collision with the objects very exact 
	//the m_rope its located at the end of the rope 
		if (angle2 >= 0 && angle2 < 90)
			m_rect.setPosition(rect.left +10, m_sprite.getPosition().y + rect.height-15 );
				else
			m_rect.setPosition((rect.width + rect.left)-15 , m_sprite.getPosition().y + rect.height -15);

	m_rect.rotate(angle);
	window.draw(m_sprite);
}

//-------------------------------------------------------------------------------------------------
//rotating the rope
void Rope::rotateRope(const sf::Time& DeltaTime)
{
	m_found_object = false;
	m_rotate = true;
	if (m_sprite.getRotation() > MIN_ANGLE && m_sprite.getRotation() < MAX_ANGLE)
	{
		changeDirection();
	}
	
	auto angle = m_direction * SPEED;
	m_sprite.rotate(angle);
}
