#include "Screens/StoreScreen.h"
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
class ActionError {};
int StoreScreen::run(sf::RenderWindow& gold_miner, int& level, int& totalMoney)
{

	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Font Font;

	int menu = 0;


	
		if ((level % 2) -1 ==0)
			startStore(gold_miner, totalMoney);

		return GOAL_SCREEN;

	
	return (-1);
}
//-----------------------------------------------------------------------------------------------------
void  StoreScreen::startStore(sf::RenderWindow& gold_miner, int& totalMoney)
{

	auto t = sf::Texture();
	t.loadFromFile("store.jpg");
	sf::Sprite s(t);

	while (gold_miner.isOpen())
	{
		gold_miner.draw(s);


		for (auto event = sf::Event(); gold_miner.pollEvent(event);)
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				gold_miner.close();
				break;
			case (sf::Event::MouseButtonReleased):
			{
				auto x = event.mouseButton.x;
				auto y = event.mouseButton.y;
				sf::Vector2f pos(x, y);

				if ((pos.x > 966 && pos.x < 1160) && (pos.y < 416 && pos.y > 300))
					return;

				//present
				if ((pos.x > 370 && pos.x < 469) && (pos.y < 402 && pos.y > 325))
				{
					if (totalMoney > 30)
					{
						srand(time(NULL));
						auto num = rand() % 2;

						if (num==0)
							totalMoney += 100;
						else //num1
							totalMoney += 30;

						m_presentDisplay = false;
					}
				}
				//diamond
				if ((pos.x > 560 && pos.x < 660) && (pos.y < 400 && pos.y > 326))
				{
					if (totalMoney > 50)
					{
						totalMoney += 100;
						m_diamondDisplay = false;
					}
				}
				//gold rock
				if ((pos.x > 785 && pos.x < 880) && (pos.y < 388 && pos.y > 326))
				{

					if (totalMoney > 40)
					{
						totalMoney += 100;
						m_bigGoldDisplay = false;
					}
				}
			}
			}
		}

		if (m_presentDisplay)
		{
			m_present.draw(gold_miner);
			m_present.MakeBigger();
		}
		if (m_diamondDisplay)
		{
			m_diamond.draw(gold_miner);
			m_diamond.MakeBigger();
		}
		if (m_bigGoldDisplay)
		{
			m_bigGold.draw(gold_miner);
			m_bigGold.MakeBigger();
		}


		if (!m_bigGoldDisplay && !m_diamondDisplay && !m_presentDisplay)
			return;
		


		
			m_text.setString("YOUR TOTAL AMOUT OF MONEY IS " + std::to_string(totalMoney) + "$                                                                 "
							"GET EXTRA MONEY FOR EACH OBJECT");
			m_text.setCharacterSize(26);
			m_text.setStyle(sf::Text::Bold);
			m_text.setPosition(20, 15);
			m_text.setFillColor(sf::Color ::Black);

		
		
			gold_miner.draw(m_text);

		gold_miner.display();
		gold_miner.clear();
	}

}