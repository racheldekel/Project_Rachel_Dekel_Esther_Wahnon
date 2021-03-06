#include "Level.h"
#include <istream>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>

const auto CORRIDOR = sf::Vector2f(150.f, 225.f);
using std::cout;
using std::endl;
using std::ifstream;

const auto BOARDER = sf::Vector2f(15.f, 150.f);


Level::Level(int levelNumber) :m_level(levelNumber)
{
	readLevel(levelNumber);
}

//----------------------------------------------------------------------------------
void Level::readLevel(int levelNumber)
{
	ifstream input;

		std::cout << levelNumber << std::endl;
		string file = std::to_string(levelNumber) + ".txt";
		input.open(file);
		if (!input.is_open())
			throw std::invalid_argument("Could not open file");


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
void Level::addOnBoard(char c,size_t i,size_t j)	
{
	
	auto pos = sf::Vector2f(j, i) * (float)(SIZE);
	pos += CORRIDOR;
	
	switch (c)
	{


	case '*': 
		m_board[i][j] = std::make_unique < bomb >(pos);

		m_bombBoard[i][j] = true;
		break;

	case '%': 
		m_board[i][j] = std::make_unique < bone >(pos);
		break;
	case '$': 
		m_board[i][j] = std::make_unique < bigGold >(pos);
		break;

	case '&': 
		m_board[i][j] = std::make_unique < smallGold >(pos);
		break;

	case '^': 
		m_board[i][j] = std::make_unique <diamond>(pos);
		break;

	case '@': 
		m_board[i][j] = std::make_unique < Present >(pos);
		break;
	case '!':
		m_board[i][j] = std::make_unique < smallRock>(pos);
		break;
	case '#':
		m_board[i][j] = std::make_unique < bigRock>(pos);
		break;

	case '~':
		m_board[i][j] = std::make_unique < Mouse>(pos);

		m_mouseLocation = sf::Vector2i(i, j);


		break;


	default:
		break;
	}
}
//---------------------------------------------------------------------
const sf::Vector2i& Level::mouseLocation()const
{
	return m_mouseLocation;
}
//_--------------------------------------------------------------------
void Level::drawStaticFigures(sf::RenderWindow& window)
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
//--------------------------------------------------------------------------------
bool Level::CheckIfBomb(size_t row, size_t col)
{

	if (m_bombBoard[row][col] == true)
	{
		return true;
	}

	return false;
}
//-----------------------------------------------------------------

Object* Level::operator()(size_t row, size_t col)
{
	if (row >= m_board.size() || col >= m_board.begin()->size())
		return nullptr;
	return m_board[row][col].get();
}
//-----------------------------------------------------
void Level::makeAllValuesFalse()
{
	for (auto row=0 ; row <getRows() ; row++)
	{
		for (auto col = 0; col < getCols(); col++)
		{

			m_bombBoard[row][col] = false;
		}

	}
}
