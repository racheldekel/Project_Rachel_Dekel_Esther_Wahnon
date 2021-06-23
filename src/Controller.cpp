#include "Controller.h"
class ActionError{};


int Controller::startGame(sf::RenderWindow& gold_miner, int& totalMoney, int level)
{

	if (level == 1)
		resetValues();
	m_levelNumber = level;
	m_moneyCounter = totalMoney;

	auto t = sf::Texture();
	t.loadFromFile("background.png");
	sf::Sprite s(t);

	auto clock = sf::Clock();
	static sf::Clock AITimer;
	static sf::Time AITime = sf::seconds(1.0f);
	m_moneySound.setBuffer(FileManager::instance().getSound(GETMONEY_s));
	m_explosionSound.setBuffer(FileManager::instance().getSound(EXPLOSION_s));
	m_goalLevel = m_goal[m_levelNumber];
	m_finish_level = false;
	m_level.read_level(m_levelNumber);

	
	while (gold_miner.isOpen())
	{
		gold_miner.draw(m_background);

		if (AITimer.getElapsedTime().asSeconds() > AITime.asSeconds()) 
		{
			m_time--;
			AITimer.restart();
		}
		
		for (auto event = sf::Event(); gold_miner.pollEvent(event);)
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					gold_miner.close();
					break;
				case (sf::Event::MouseButtonReleased):
				{
					if (m_rope.getRopeState())
					{

						if (!mouse_button_released(event))
						{
							resetValues();
							return EXIT;
						}


						break;
					}
				}
				case (sf::Event::KeyPressed):
				{
					if ((event.key.code == sf::Keyboard::Down))
					{
						if (m_rope.getRopeState())
						{

							if (!mouse_button_released(event))
							{
								resetValues();
								m_level.set_Board().clear();
								return EXIT;

							}
							break;
						}
					}
				}
			}
		}
		
		drawAllObject(gold_miner);
		m_player.draw(gold_miner);

		//moving the mouse while it has not been taken by the player 

		if( m_level(m_level.mouseLocation().x, m_level.mouseLocation().y) != nullptr && m_mouseMoving)
			m_level(m_level.mouseLocation().x, m_level.mouseLocation().y)->moveMouse();


		update_state(gold_miner, clock.getElapsedTime() * 10.f);

		auto passedTime = clock.restart().asSeconds();
		m_rope.draw(gold_miner);

		if (m_drawMoney)
			gold_miner.draw(m_text);


		gold_miner.display();
		gold_miner.clear();
		clock.restart();

		if (m_time == 0)
		{
			if (m_moneyCounter < m_goalLevel)
			{
				totalMoney = 0;
				resetValues();
				m_level.set_Board().clear();
					return TIME_OVER;
			}

			else
				m_finish_level = true;

		}
		
		if (m_finish_level || checkIfBoardEmty())

		{
			m_level.set_Board().clear();
			m_level.makeAllValuesFalse();
			totalMoney = m_moneyCounter;
			saveValue(m_moneyCounter);
			m_time = 60;
			m_levelNumber++;
			m_mouseMoving = true;
			m_drawMoney = false;
			gold_miner.clear();
			break;
		}

	}

}
//------------------------------------------------------------------------------
void Controller::resetValues()
{
	
	m_level.makeAllValuesFalse();
	m_time = 60;
	m_level = 1;
	m_levelNumber = 1;
	m_moneyCounter = 0;
	m_mouseMoving = true;
	m_drawMoney = false;
}
//----------------------------------------------------------------------------------------------------
void Controller::update_state(sf::RenderWindow& gold_miner, const sf::Time& timePass)
{
	//if we have found and object and we are taking it 
			if (m_getObject)
			{
				
				if (m_level.set_Board()[m_row][m_col] != nullptr)
				{
					//bring it up and once is done the function moveOBJECT WILL RETURN false
					if (!m_level(m_row, m_col)->moveObject(timePass, m_rope.get_position(), m_level(m_row, m_col)->getAngle()))
					{
						// once we are done taking the object 
						m_money = m_level(m_row, m_col)->get_value();
						m_drawMoney = true;
						drawMoney(gold_miner);
						m_moneySound.play();
						m_moneyCounter += m_money;
						m_level.set_Board()[m_row][m_col] = nullptr;
						m_getObject = false;
					}
				}
				if (m_level.CheckIfBomb(m_row, m_col))
				{
					auto number=0;
					m_getObject = false;

					number = m_row - 3 <= 0 || m_col - 3 <= 0 ? 1 : 3;


					for (int row = m_row- number; row < m_row +number; row++)
					{
						for (int col = m_col- number; col < m_col + number; col++)
						{
							m_level.set_Board()[row ][col] = nullptr;
							
						}
					}

				}
			}

			//m_drawMoney = false;

			if (m_rope.isOpen())
			{
				m_drawMoney = false;
				m_rope.openRope(timePass);

				m_player.playerGrab();
				
				if (m_checked_object)
				{
					int row = 0, col = 0;
					// if we found an object , theres no need to check for more objects 
					// the fucntion isAttact in case something is found would return the values found and put it in the row and col
					
					if (isAttach(row, col))
					{	

						if (m_level.CheckIfBomb(row, col))
						{
							
							m_explosion.setLocation(sf::Vector2f(col, row)*SIZE );
							m_explosionSound.play();

						
						}

						m_rope.connectToObject(timePass);
							m_rope.foundObject();
							// so it wont enter another time
							m_checked_object = false;
							m_level(row, col)->setAngle(m_ropeAngle);
							m_row = row, m_col = col;
							m_getObject = true;

					}
				}

			}
			//in case the user has not press the botton the rope is just rotating the whole time
			else
			{
				m_rope.rotateRope(timePass);
				m_player.playerStand();
				m_checked_object = true;
			}	
}
//---------------------------------------------------------------------------
void Controller:: drawMoney(sf::RenderWindow& gold_miner)
{
	m_text.setString(std::to_string(m_money)+"$");
	m_text.setCharacterSize(52.5);
	m_text.setStyle(sf::Text::Bold);
	m_text.setPosition(315, 15);
	m_text.setFillColor(sf::Color:: Black);
}
//---------------------------------------------------------------------------
void Controller::saveValue(int &money)
{
	value = money;
}
//-----------------------------------------------------------------------------
int Controller::getLevel()const
{
	return m_levelNumber;
}
//--------------------------------------------------------
bool Controller::levelFinished()
{
	return m_finish_level;
}
//--------------------------------------------------------------------------
bool Controller::mouse_button_released(sf::Event event)
{
	auto x1 = event.mouseButton.x;
	auto y1 = event.mouseButton.y;
	sf::Vector2i pos1(x1, y1);

	if ((pos1.x > 1070 && pos1.x < 1133) && (pos1.y < 82 && pos1.y > 26))
		return false;

	m_ropeAngle = m_rope.getRotation();
	m_rope.changeState();

		return true;
}
//--------------------------------------------------------------------------------------------
void Controller::drawAllObject(sf::RenderWindow& gold_miner)
{
	m_level.draw_static_figures(gold_miner);
	if (m_explosion.m_explode)
	{
		m_explosion.draw(gold_miner);
	}
	m_toolbar.draw(gold_miner, m_levelNumber, m_moneyCounter, m_goalLevel, m_time);
}
//----------------------------------------------------------------
bool Controller::isAttach(int &final_row, int &final_col)
{
	auto floatrect = m_rope.get_objects_bounds();

	for (auto row = 0; row < m_level.getRows(); ++row) 
	{
		for (auto col = 0; col < m_level.getCols(); ++col)
		{
			if (m_level(row, col) != nullptr)
			{
				if (m_level(row, col)->is_intersected(floatrect))
				{
					final_row = row;
					final_col = col;

					if (m_level(m_level.mouseLocation().x, m_level.mouseLocation().y) == m_level(row, col))
						m_mouseMoving = false;
					return true;
				}
			}
		}
	}

		return false;
}
//----------------------------------------------------------------------------------------------
bool Controller:: checkIfBoardEmty()
{

	for (auto row = 0; row < m_level.getRows(); ++row)
	{
		for (auto col = 0; col < m_level.getCols(); ++col)
		{
			if (m_level(row, col) != nullptr)
			{
				return false;
			}
		}
	}

	return true;
}
//--------------------------------------------------------------------------------------------------------------------------------------------

Controller::Explosion::Explosion()
{
		m_explosion_sprite.scale(0.25f, 0.25f);
	auto rect = m_explosion_sprite.getGlobalBounds();
	m_explosion_sprite.setScale(sf::Vector2f(((float)SIZE / rect.height * 1.5),
		((float)SIZE / rect.height * 1.5)));
}

void Controller::Explosion::setLocation(const sf::Vector2f& location)
{
		m_explode = true;
		m_explosion_sprite.setPosition(location);
		
		//m_explosion_sprite.setOrigin({ rect.width / 2, rect.height / 2 });
}

void Controller::Explosion::draw(sf::RenderWindow& gold_miner)
{
	{
		m_explosion_sprite.setTextureRect(sf::IntRect(256 * currentState % 8, 248 * currentState / 6, 256, 248)); //rows
		gold_miner.draw(m_explosion_sprite);
		currentState++;
		if (currentState == 32)
		{
			currentState = 0;
			m_explode = false;
		}
	}
}
