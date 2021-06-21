#include "Objects/Mouse.h"

sf::Vector2f Mouse :: getPosition()
{
	return m_sprite.getPosition();
}

void  Mouse ::setPosition(sf::Vector2f pos) {
	m_sprite.setPosition(pos.x + 1, pos.y + 1);

}
void Mouse ::move(float passedTime)
{
	float distance = 120.f * passedTime;

	sf::Vector2f pos = m_sprite.getPosition();
	m_sprite.setPosition(pos * distance);

}
