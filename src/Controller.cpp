#include "Controller.h"
class ActionError{};


int Controller::startGame(sf::RenderWindow& gold_miner)
{
	auto clock = sf::Clock();
	auto t = sf::Texture();
	t.loadFromFile("background.png");
	sf::Sprite s(t);
	static sf::Clock AITimer;
	static sf::Time AITime = sf::seconds(1.0f);
	
	m_finish_level = false;
	m_goalLevel = m_goal[m_levelNumber];

	m_level.read_level(m_levelNumber);

	
	while (gold_miner.isOpen())
	{
		gold_miner.draw(s);

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
								return EXIT;


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
		{
			
			gold_miner.draw(m_text);

		}

		gold_miner.display();
		gold_miner.clear();
		clock.restart();

		if (m_time == 0)
		{
			m_time = 60;

			if (m_moneyCounter < m_goalLevel)
			{
				
				resetValues();
				
				return TIME_OVER;
				

			}

			else
				m_finish_level = true;

		}
		
		if (m_finish_level)
		{
			m_levelNumber++;
			m_mouseMoving = true;
			break;
		}


	}

	
}
//------------------------------------------------------------------------------
void Controller::resetValues()
{

	m_level = 1;
	m_levelNumber = 1;
	m_moneyCounter = 0;
	m_mouseMoving = true;
}
//-----------------------------------------------------------------------------

void Controller::update_state(sf::RenderWindow& gold_miner, const sf::Time& timePass)
{

	//if we have found and object and we are taking it 
	if (m_getObject)
	{
		
		//bring it up and once is done the function moveOBJECT WILL RETURN false
		if (!m_level(m_row, m_col)->moveObject(timePass, m_rope.get_position(), m_level(m_row, m_col)->getAngle()))
		{

			// once we are done taking the object 
			m_money =m_level(m_row, m_col)->get_value();
			m_drawMoney = true;
			drawMoney(gold_miner);
			m_moneyCounter +=m_money;
			
			m_level.set_Board()[m_row][m_col] = nullptr;
			m_getObject = false;
			
			
		}
			

	}

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
					
					
					m_rope.connectToObject(timePass);
						m_rope.foundObject();
						cout << "found intersection with item at " << row << " " << col << endl;
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
	auto represent = sf::seconds(5.f);
	m_text.setString(std::to_string(m_money)+"$");
	m_text.setCharacterSize(35);
	m_text.setStyle(sf::Text::Bold);
	m_text.setPosition(210, 10);
	m_text.setFillColor(sf::Color:: Yellow);

	
}
//---------------------------------------------------------------------------
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

	if ((pos1.x > 534 && pos1.x < 581) && (pos1.y < 46 && pos1.y > 17))
		return false;

	m_ropeAngle = m_rope.getRotation();

	m_rope.changeState();

	
	return true;
}
//--------------------------------------------------------------------------------------------
void Controller::drawAllObject(sf::RenderWindow& gold_miner)
{
	m_level.draw_static_figures(gold_miner);
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
					
					if (m_level(m_level.mouseLocation().x, m_level.mouseLocation().y) == m_level(row, col))
						m_mouseMoving = false;

					final_row = row;
					final_col = col;
					return true;
				}
			}
		}
	}

		return false;
	}
	
	
//----------------------------------------------------------------------------------------------

