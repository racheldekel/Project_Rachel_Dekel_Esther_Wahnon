#pragma once
const auto NUM_OF_LEVELS = 6;
const auto EXIT = 0;
const auto TIME_OVER = 1;
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include "FileManager.h"
#include <vector>
#include "Level.h"
#include <fstream>
#include <sstream>
#include "Objects/diamond.h"
#include "Toolbar.h"
using std::vector;
#include <iostream>
#include <string>
#include <queue>
class Controller
{
public:
	Controller() {};
	~Controller() = default;
	int startGame(sf::RenderWindow& gold_miner);
	void update_state(const sf::Time& timePass = sf::Time());
	void drawAllObject(sf::RenderWindow& gold_miner);
	bool levelFinished();
	bool mouse_button_released(sf::Event event);
	int getLevel()const;
	bool isAttach(int& row, int& col);
	void resetValues();
private:


	Mouse m_mouse{{} };
	bool m_checked_object = true;
	int m_moneyCounter = 0;
	int m_goalLevel = 0;
	int  m_time = 60;
	Toolbar m_toolbar;
	
	Player m_player = Player{ {400.f, 30.f} };
	Rope m_rope = Rope{ {400.f, 65.f} };
	bool m_finish_level = true;
	Level m_level;
	sf::Vector2f m_position;

	void  changeObjectState();
	int m_row = 0;
	int m_col = 0;
	int m_levelNumber = 1;
	int m_value=0;
	bool m_getObject = false;
	float m_ropeAngle;
	//int m_goal[7] = {0, 300, 500, 800, 1100, 1400, 1700 };
	int m_goal[7] = { 0, 200, 300, 400, 1100, 1400, 1700 };
};