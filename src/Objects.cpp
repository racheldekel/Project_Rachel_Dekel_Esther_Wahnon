#include "Objects/Objects.h"

//_--------------------------------------------------------------------------------
void Objects::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

//---------------------------------------------------------------------------------------
int Objects:: get_value() const
{
	return m_value;
};
//_-------------------------------------------------------------------------------------
bool Objects:: is_intersected(const sf::FloatRect & rect)
{
	return rect.intersects(m_sprite.getGlobalBounds());
}
//--------------------------------------------------------------------------------------------------
bool Objects:: moveObject(const sf::Time & timePass, sf::Vector2f posRope, float angle)
{
	auto& pos = m_sprite.getPosition();
	auto distance = hypotf(pos.x - posRope.x, pos.y - posRope.y);
	/*auto distance = sqrt(pow(pos.x - posRope.x, 2) + (pow(pos.y - posRope.y, 2)));*/
	if (distance> 80)
	{
		m_sprite.move(sf::Vector2f(posRope.x - pos.x, posRope.y - pos.y)* timePass.asSeconds() * 3.f);

		return true;

	}


	else
		return false;


}
//---------------------------------------------------------------------------------------------
void Objects:: moveMouse() 
{

	auto pos = m_sprite.getPosition();

	if (m_mouseMoveRight)
	{
		m_sprite.setScale(-1, 1);
		m_sprite.move(1, 0);

		if (pos.x > 1048)
			m_mouseMoveRight = false;



	}
	else
	{
		m_sprite.setScale(1, 1);
		m_sprite.move(-1, 0);

		
		if (pos.x < 153)
		{
			
			m_mouseMoveRight = true;
		}
	}

}