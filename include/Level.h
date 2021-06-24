#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include  "Object/Object.h"


#include  "Object/bomb.h"
#include  "Object/bone.h"
#include "Object/diamond.h"
#include "Object/bigGold.h"
#include  "Object/SmallGold.h"
#include "Object/Present.h"
#include "Object/bigRock.h"
#include "Object/smallRock.h"
#include "Object/Rope.h"
#include "Object/Player.h"
#include "Object/Mouse.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using std::ifstream;
using std::string;


class Level
{

public:
	bool CheckIfBomb(size_t row, size_t col);
	Level()= default;
	void addOnBoard(char c, size_t i, size_t j);
	Level(int levelNumber);
	Object* operator()(size_t row, size_t col);
	void drawStaticFigures(sf::RenderWindow& window);
	void setBoardSize(int rows, int cols);
	void readLevel(int levelNumber);
	int getCols() const;
	int getRows()const;
	vector<vector<std::unique_ptr<Object>>>&set_Board()
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

	std::vector <std::vector<std::unique_ptr<Object>>> m_board;
	bool m_bombBoard[10][25] = { false };







};