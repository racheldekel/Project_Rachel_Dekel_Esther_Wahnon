#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Controller.h"

class GameScreen : public Screen
{
public:

	GameScreen() {};
	~GameScreen() {};
	
	virtual int run(sf::RenderWindow& gold_miner);


private:
	Controller m_controller;
};