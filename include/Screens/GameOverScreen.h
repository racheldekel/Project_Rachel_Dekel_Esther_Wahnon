#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "ManagerScreen.h"

class GameOverScreen : public Screen
{
public:

	GameOverScreen() {};
	~GameOverScreen() {};

	virtual int run(sf::RenderWindow& gold_miner, int& level, int& totalMoney);
	bool  mouse_button_released(sf::Event event);

private:
	ManagerScreen s;

	
	Controller m_controller;
};