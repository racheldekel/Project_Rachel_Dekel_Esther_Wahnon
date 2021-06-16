#include "Level.h"
#include <istream>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>

const auto CORRIDOR = sf::Vector2f(150.f, 225.f);
//const auto CORRIDOR = sf::Vector2f(350.f, 300.f);

using std::cout;
using std::endl;
using std::ifstream;

const auto BOARDER = sf::Vector2f(15.f, 150.f);

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
		string file = std::to_string(levelNumber) + ".txt";
		//string file = "1.txt";
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
	pos += CORRIDOR;
	
	switch (c)
	{


	case '*': //  1 צינור -
		m_board[i][j] = std::make_unique < bomb >(pos);
		break;

	case '%': //  1 צינור -
		m_board[i][j] = std::make_unique < bone >(pos);
		break;
	case '$': //  1 צינור -
		m_board[i][j] = std::make_unique < bigGold >(pos);
		break;

	case '&': //  1 צינור -
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
//-----------------------------------------------------
