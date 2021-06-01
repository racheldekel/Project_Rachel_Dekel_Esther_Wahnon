#include "Objects/rope.h"


void rope::update_state()
{

	float timePass = m_clock.restart().asSeconds();


	if (m_open)
		openRope(timePass);



	else
	{
		rotateRope(timePass);
	}

}
//----------------------------------------------------------------------
void rope::openRope(float timePass)
{
	// do the time  in float get parameter 

	float LengthAddition = rope ::lenghRope * timePass;


	auto scale = m_sprite.getScale();

	scale.y += LengthAddition;

	m_sprite.setScale(scale);

	std::cout << scale.y <<" "<<timePass<<" "<< LengthAddition << std::endl;

}
//-----------------------------------------------------------------------------------
void rope::draw(sf::RenderWindow& window)
{
	update_state();

	//window.clear();
	window.draw(m_sprite);
}
//-----------------------------------------------------------------------------------
void rope ::rotateRope(float timePass)
{
	if (m_sprite.getRotation() >= MAX_ANGLE)
		m_direction = RIGHT;
	else if (m_sprite.getRotation() <= -MAX_ANGLE)
		m_direction = LEFT;

	//std::cout << m_sprite.getRotation()<<std:: endl;
	m_sprite.setRotation(m_sprite.getRotation()+( 22.f* timePass *m_direction ));
}