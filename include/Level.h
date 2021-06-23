#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include  "Objects/Objects.h"


#include  "Objects/bomb.h"
#include  "Objects/bone.h"
#include "Objects/diamond.h"
#include "Objects/bigGold.h"
#include  "Objects/SmallGold.h"
#include "Objects/Present.h"
#include "Objects/bigRock.h"
#include "Objects/smallRock.h"
#include "Objects/Rope.h"
#include "Objects/Player.h"
#include "Objects/Mouse.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::ifstream;
using std::string;

//const auto SIZE = 60;
class Level
{

public:
	bool CheckIfBomb(size_t row, size_t col);
	Level()= default;
	void addOnBoard(char c, size_t i, size_t j);
	Level(int levelNumber);
	Objects* operator()(size_t row, size_t col);
	Objects& getObjectAt(size_t row, size_t col) {
		return *m_board[row][col];
	}
	void draw_static_figures(sf::RenderWindow& window);
	void setBoardSize(int rows, int cols);
	void read_level(int levelNumber);
	int getCols() const;
	int getRows()const;
	vector<vector<std::unique_ptr<Objects>>>&set_Board()
	{
		return m_board;
	}
	const sf::Vector2i& mouseLocation()const;
	void setNewArray();
	void makeAllValuesFalse();
protected :


private:
	int m_row = 0;
	int m_col = 0;
	int m_level = 0;
	sf::Vector2f m_pos;
	sf::Vector2i m_mouseLocation;

	std::vector <std::vector<std::unique_ptr<Objects>>> m_board;
	bool m_bombBoard[10][25] = { false };







};