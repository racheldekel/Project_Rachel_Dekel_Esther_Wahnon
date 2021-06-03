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

const auto SIZE = 60.f;
class Level
{

public:

	Level()= default;
	void addOnBoard(const char c, const size_t i, const size_t j);
	Level(int levelNumber);

	Objects* operator()(size_t row, size_t col);
	void draw_static_figures(sf::RenderWindow& window);
	void setBoardSize(int rows, int cols);
	void read_level(int levelNumber);
	int getCols() const;
	int getRows()const;

private:
	int m_row = 0;
	int m_col = 0;
	int m_level = 0;
	sf::Vector2f m_pos;

	std::vector <std::vector<std::unique_ptr<Objects>>> m_board;







};