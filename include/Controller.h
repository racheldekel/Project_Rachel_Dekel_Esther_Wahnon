#pragma once
const auto NUM_OF_LEVELS = 6;
const auto EXIT = 0;
const auto TIME_OVER = 1;
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
	void drawMoney(sf::RenderWindow& gold_miner);
	int startGame(sf::RenderWindow& gold_miner, int& totalMoney, int level);
	void update_state(sf::RenderWindow & gold_miner, const sf::Time& timePass = sf::Time());
	void drawAllObject(sf::RenderWindow& gold_miner);
	bool levelFinished();
	void saveValue(int & money);
	bool mouse_button_released(sf::Event event);
	int getLevel()const;
	bool isAttach(int& row, int& col);
	void resetValues();
	bool checkIfBoardEmty();

private:
	struct Explosion
	{
		Explosion();

		void setLocation(const sf::Vector2f& location);

		void draw(sf::RenderWindow& gold_miner);


		bool m_explode = false;
		sf::Sprite m_explosion_sprite = sf::Sprite(FileManager::instance().get_icon(12), sf::IntRect(0, 0, 256, 248));
		size_t currentState = 0;
	};

	bool m_drawMoney = false;
	int m_money = 0;
	sf::Sprite m_background = sf::Sprite(FileManager::instance().get_icon(BACKGROUND));
	sf::Text m_text = sf::Text({}, *FileManager::instance().getFont(0));
	Mouse m_mouse{{} };
	bool m_checked_object = true;
	int m_moneyCounter = 0;
	int m_goalLevel = 0;
	int  m_time = 60;
	Toolbar m_toolbar;
	Player m_player = Player{ {600.f, 90.f} };
	Rope m_rope = Rope{ {578.f, 118.f} };
	bool m_finish_level = true;
	Level m_level;
	bool m_mouseMoving= true;
	sf::Vector2f m_position;
	Explosion m_explosion;
	int m_row = 0;
	int m_col = 0;
	int m_levelNumber = 1;
	int m_value=0;
	bool m_getObject = false;
	float m_ropeAngle;
	int value;
	int m_goal[7] = {0, 300, 500, 800, 1100, 1400, 1700 };
	sf::Sound m_moneySound;
	sf::Sound m_explosionSound;
};