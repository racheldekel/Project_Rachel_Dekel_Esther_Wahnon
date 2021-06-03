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
void rope::changeDirection()
{
	m_direction = m_direction == 1 ? -1 : 1;
}
rope::rope(sf::Vector2f pos) : Objects(pos)
{
	m_sprite.setTexture(FileManager::instance().get_icon(ROPE));
	m_sprite.setPosition(pos);
	auto rect = m_sprite.getGlobalBounds();
	m_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height),
		((float)SIZE / rect.height)));
	m_sprite.setOrigin({ rect.width / 2, 0 });

}
//----------------------------------------------------------------------
void rope::openRope(float timePass)
{
	// do the time  in float get parameter 

	float LengthAddition = rope ::lenghRope * timePass;


	auto scale = m_sprite.getScale();

	scale.y += LengthAddition;

	m_sprite.setScale(scale);


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
	if (m_sprite.getRotation() > MIN_ANGLE && m_sprite.getRotation() < MAX_ANGLE)
	{
		changeDirection();
	}


	m_sprite.rotate(22.f* timePass * m_direction );
}

