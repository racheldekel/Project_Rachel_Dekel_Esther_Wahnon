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
	for (size_t i = 0; i < rows; i++)
		m_board[i].resize(cols);

	for (size_t i = 0; i < rows; i++)
	{
		input.get();
		for (size_t j = 0; j < cols; j++)
		{
			c = input.get();
			addOnBoard(c, i, j);
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

	auto pos = sf::Vector2f(i, j) ;
	//pos.x += P_SIZE / 2;
	//pos.y += P_SIZE / 2;
	switch (c)
	{


	case '=': //אובייקט ההתחלה
		m_board[i][j] = std::make_unique < player >(pos);



		break;


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
		m_board[i][j] = std::make_unique < present >(pos);
		break;
	case '!':
		m_board[i][j] = std::make_unique < smallRock>(pos);
		break;
	case '#':
		m_board[i][j] = std::make_unique < bigRock>(pos);
		break;

	case '+':
		m_board[i][j] = std::make_unique < rope>(pos);
		break;
	case '~':
		m_board[i][j] = std::make_unique < mouse>(pos);
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

			if (col == nullptr)
				continue;

			else
				col->draw(window);
		}

	}
	
}
