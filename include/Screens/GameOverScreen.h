/*#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
class GameOverScreen : public Screen
{
public:

	GameOverScreen() {};
	~GameOverScreen() {};
	virtual int run(sf::RenderWindow& gold_miner) { return 1; };


private:
};m_sprite.setTexture(*(FileManager::instance().get_icon(MOUSE)));
m_sprite.setPosition(pos);
auto rect = m_sprite.getGlobalBounds();
m_sprite.setOrigin({ rect.width / 2, rect.height / 2 });
m_sprite.setScale(sf::Vector2f(0.25f, 0.25f));*/