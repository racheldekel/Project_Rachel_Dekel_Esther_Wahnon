#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Controller.h"

class GameOverScreen : public Screen
{
public:

	GameOverScreen() {};
	~GameOverScreen() {};

	virtual int run(sf::RenderWindow& gold_miner, int& level);
	bool  mouse_button_released(sf::Event event);

private:
	Controller m_controller;
};