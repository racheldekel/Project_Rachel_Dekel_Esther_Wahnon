#include "Object/Object.h"
//_--------------------------------------------------------------------------------
void Object::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
//---------------------------------------------------------------------------------------
int Object:: get_value() const
{
	return m_value;
};
//_-------------------------------------------------------------------------------------
bool Object:: is_intersected( sf::FloatRect & rect)
{
	return rect.intersects((m_sprite.getGlobalBounds()));
}
//--------------------------------------------------------------------------------------------------
bool Object:: moveObject(const sf::Time & timePass, sf::Vector2f posRope, float angle)
{
	auto& pos = m_sprite.getPosition();
	auto distance = hypotf(pos.x - posRope.x, pos.y - posRope.y);
	if (distance> 80)
	{
		m_sprite.move(sf::Vector2f(posRope.x - pos.x, posRope.y - pos.y)* timePass.asSeconds() * 2.f);
			return true;
	}
	else
		return false;
}
//---------------------------------------------------------------------------------------------
void Object:: moveMouse() 
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
			m_mouseMoveRight = true;
	}
}
//----------------------------------------------------------------------------
void Object::MakeBigger()
{
	m_sprite.setScale(1.75, 1.75);
}
//------------------------------------------------------------------------------
