#include "Objects/rope.h"


const auto SPEED = 0.5f;

void Rope::update_state(const sf::Time& timePass)
{

	//float timePass = m_clock.restart().asSeconds();
	//std::cout << timePass << std::endl;

	if (m_open)
		openRope(timePass);
	else
	{
		rotateRope(timePass);
	}

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
	//m_sprite.setRotation(MIN_ANGLE);

}
//----------------------------------------------------------------------
void Rope::openRope(const sf::Time& time )
{
	// do the time  in float get parameter 

	float LengthAddition = Rope ::lenghRope * time.asSeconds(); //* time.asSeconds();


	auto scale = m_sprite.getScale();

	scale.y += LengthAddition;

	m_sprite.setScale(scale);


}
//-----------------------------------------------------------------------------------
void Rope::draw(sf::RenderWindow& window)
{

	update_state();

	//window.clear();
	window.draw(m_sprite);
}
//-----------------------------------------------------------------------------------
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

