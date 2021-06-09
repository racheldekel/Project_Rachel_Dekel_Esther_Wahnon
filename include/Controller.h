#pragma once
const auto NUM_OF_LEVELS = 6;
const auto EXIT = 0;
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
	int mouse_button_released(sf::Event event);
	int getLevel()const;
	//const vector<vector<std::unique_ptr<Objects>>>& board;
	bool isAttach();
private:

	int m_moneyCounter = 0;
	int m_goalLevel = 0;
	int  m_time = 0;
	Toolbar m_toolbar;
	
	Player m_player = Player{ {400.f, 30.f} };
	Rope m_rope = Rope{ {400.f, 65.f} };
	bool m_finish_level = true;
	Level m_level;
	sf::Vector2f m_position;
	Mouse m_mouse = Mouse{ {},{} };


//	bool m_endOfGame = false;

	int m_levelNumber = 1;
	int m_value=0;
	diamond m_diamond = diamond{ {},{} };
	smallGold m_smallGold = smallGold{ {}, {} };

	
};