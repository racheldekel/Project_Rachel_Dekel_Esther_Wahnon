#pragma once
const auto NUM_OF_LEVELS = 6;

#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include "FileManager.h"
#include <vector>
#include "Level.h"
#include <fstream>
#include <sstream>


using std::vector;
#include <iostream>
#include <string>
#include <queue>
class Controller
{
public:
	Controller() {};
	~Controller() = default;
	void startGame(sf::RenderWindow& gold_miner);
	void drawAllObject(sf::RenderWindow& gold_miner);
	bool levelFinished();
	void mouse_button_released(sf::Event event);
	int getLevel()const;
	//const vector<vector<std::unique_ptr<Objects>>>& board;
	
private:
	Player m_player = Player{ {400.f, 30.f} };
	Rope m_rope = Rope{ {400.f, 65.f} };
	bool m_finish_level = true;
	Level m_level;
	sf::Vector2f m_position;

//	bool m_endOfGame = false;

	int m_levelNumber = 1;



	
};