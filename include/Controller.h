#pragma once
const int NUM_OF_LEVELS = 6;

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
	~Controller() {};
	void startGame(sf::RenderWindow& gold_miner);
	void drawAllObject(sf::RenderWindow& gold_miner);
	bool levelFinished();
	void mouse_button_released(sf::Event event);
	int getLevel()const;
		//const vector<vector<std::unique_ptr<Objects>>>& board);
	
private:

	bool m_finish_level = true;
	Level m_level;
	int long  m_position_func = 0;
	int m_num_object = 0;
	sf::Vector2f m_position;

	bool m_read = 0;
	bool m_out = 0;
	bool m_endOfGame = false;


	int m_levelNumber = 0;



	
};