#include "Level.h"
#include <istream>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;

const auto BOARDER = sf::Vector2f(10.f, 100.f);

class FileError {};

Level::Level(int levelNumber) :m_level(levelNumber)
{
	read_level(levelNumber);
}

//----------------------------------------------------------------------------------
void Level::read_level(int levelNumber)
{
	ifstream input;
	try
	{
		//string file = std::to_string(levelNumber) + ".txt";
		string file = "1.txt";
		input.open(file);
		if (!input.is_open())
		{
			throw FileError();
		}
	}
	catch (FileError)
	{
		std::cerr << "could not open file\n";
		exit(EXIT_FAILURE);
	}


	int rows, cols;
	char c;
	input >> rows >> cols;



	m_row = rows, m_col = cols;

	m_board.resize(rows);
	for (auto& cell : m_board)
		cell.resize(cols);

	for (size_t i = 0; i < rows; i++)
	{
		input.get();
		for (size_t j = 0; j < cols; j++)
		{
			addOnBoard(input.get(), i, j);
		}
	}

}


//-------------------------------------------------------
/*
bool Level::check_collision(const sf::FloatRect& rect)
{
	for (auto row = 0; row < m_board.size(); row++)

	{
		for (auto col = 0; col < m_board[row].size(); col++)
		{

			if (m_board[row][col]->m_object.getGlobalBounds().intersects(rect))
				return true;



		}
	}
	return false;
}*/
//------------------------------------------------
int Level::getRows() const
{

	return m_row;
}
//-------------------------------------------
int Level::getCols() const
{

	return m_col;
}
//--------------------------------------------------
void Level::addOnBoard(const char c,const size_t i,const size_t j)	
{
	
	
	auto pos = sf::Vector2f(j, i) * (float)(SIZE);
	pos.x += SIZE/ 2;
	pos.y += SIZE / 2;
	
	//if (c == '=')
	//	std::cout << "alls good";

	switch (c)
	{


	//case '=': //אובייקט ההתחלה
	//	m_board[i][j] = std::make_unique <Player>(pos);

	//	

	//	break;


	case '*': //  1 צינור -
		m_board[i][j] = std::make_unique < bomb >(pos, 0);
		break;

	case '%': //  1 צינור -
		m_board[i][j] = std::make_unique < bone >(pos, 5);
		break;
	case '$': //  1 צינור -
		m_board[i][j] = std::make_unique < bigGold >(pos, 100);
		break;

	case '&': //  1 צינור -
		m_board[i][j] = std::make_unique < smallGold >(pos, 50);
		break;

	case '^': 
		m_board[i][j] = std::make_unique <diamond>(pos, 100);
		break;

	case '@': 
		m_board[i][j] = std::make_unique < Present >(pos, 100);
		break;
	case '!':
		m_board[i][j] = std::make_unique < smallRock>(pos, 15);
		break;
	case '#':
		m_board[i][j] = std::make_unique < bigRock>(pos, 30);
		break;

	//case '+':
	//	m_board[i][j] = std::make_unique < Rope>(pos);
	//	break;
	case '~':
		m_board[i][j] = std::make_unique < Mouse>(pos, 2);
		break;

	

		


	default:
		break;
	}
}
//---------------------------------------------------------------------
void Level::draw_static_figures(sf::RenderWindow& window)
{
	
	for (const auto& row : m_board)

	{

		for (const auto& col : row)
		{

			if (col != nullptr)
				col->draw(window);
		}

	}
	
}
//------------------------------------
Objects* Level::operator()(size_t row, size_t col)
{
	if (row >= m_board.size() || col >= m_board.begin()->size())
		return nullptr;
	return m_board[row][col].get();
}
