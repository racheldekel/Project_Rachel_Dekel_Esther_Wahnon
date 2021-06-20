#pragma once
#include "Screen.h"
#include <SFML/Graphics.hpp>
#include "Controller.h"
class StoreScreen : public Screen
{
public:

	StoreScreen() {};
	~StoreScreen() {};
	virtual int run(sf::RenderWindow& gold_miner, int& level, int& totalMoney);
	void  startStore(sf::RenderWindow& gold_miner, int& totalMoney);
	sf::Text m_text = sf::Text({}, *FileManager::instance().getFont(0));
private:
	bool m_presentDisplay = true;
	bool m_diamondDisplay = true;
	bool m_bigGoldDisplay = true;
	Present m_present{ {420.f, 365.f} };
	diamond m_diamond{ {610.f , 365.f} };
	bigGold m_bigGold{ {830.f, 365.f} };

};

