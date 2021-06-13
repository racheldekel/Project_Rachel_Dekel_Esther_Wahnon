#include "Controller.h"
class ActionError{};

//const auto SIZE = 60;

int Controller::startGame(sf::RenderWindow& gold_miner)
{
	auto clock = sf::Clock();
	auto t = sf::Texture();
	t.loadFromFile("background.png");
	sf::Sprite s(t);

	
	m_finish_level = false;

	m_level.read_level(m_levelNumber);

	
	
	while (gold_miner.isOpen())
	{
		gold_miner.draw(s);

		if (m_finish_level)
		{
			m_levelNumber++;

			break;
		}

		
		
		for (auto event = sf::Event(); gold_miner.pollEvent(event);)
		{
			try
			{
				
				switch (event.type)
				{
				case sf::Event::Closed:
					gold_miner.close();
					break;
				case sf::Event::MouseButtonReleased:
				{
					if (m_rope.getRopeState())
					{

						if (!mouse_button_released(event))
							return EXIT;


						break;
					}
					case sf::Event::KeyPressed:
					throw ActionError();

				}
				}
			}
			catch (ActionError)
			{
				std::cout << "Please click the mouse" << std::endl;

			}
		}
		
		drawAllObject(gold_miner);
		m_player.draw(gold_miner);


		
		update_state(clock.getElapsedTime()*10.f);

		

		m_mouse.move(15);
		auto passedTime = clock.restart().asSeconds();
		m_rope.draw(gold_miner);
		gold_miner.display();
		m_mouse.move(passedTime);
		gold_miner.clear();
		clock.restart();


	}

	//return 1;
}
//------------------------------------------------------------------------------


void Controller::update_state(const sf::Time& timePass)
{
	if (m_getObject)
	{

		
		if (!m_level(m_row, m_col)->moveObject(timePass))
		{
			auto money =m_level(m_row, m_col)->get_value();

			m_moneyCounter += money;
			m_level.setBoard()[m_row][m_col] = nullptr;
			m_getObject = false;
		}
			

	}




		if (m_rope.isOpen())
		{
			m_rope.openRope(timePass);

			if (m_checked_object)
			{
				int row = 0, col = 0;
				// if we found an object , theres no need to check for more objects 
				if (isAttach(row, col))
				{
					m_rope.connectToObject(timePass);
					m_rope.foundObject();
					cout << "found intersection with item at " << row << " " << col << endl;
					// so it wont enter another time
					m_checked_object = false;

					m_row = row, m_col = col;
					m_getObject = true;
					//m_level.getObjectAt(row, col);
					//m_level(row, col)=nullptr;
					//m_level.setBoard()[object->getPosition().y][object->getPosition().x] = nullptr;
					//m_level.setBoard()[row][col] = nullptr;
	
				}
			}

		}

		else
		{
			m_rope.rotateRope(timePass);

			m_checked_object = true;

		}


	

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

					final_row = row;
					final_col = col;
				//	m_level.setBoard()[row][col] = nullptr;
					return true;
				}
				//cout << floatrect.width << " " << floatrect.height << endl;
			
			}
		}
	}

		return false;
	}
	/*
	//auto current_location=  {400.f, 65.f};
	auto current_location = m_rope.get_position();


	auto direction = sf::Vector2f(cos(m_rope.getRotation()) * SIZE, sin(m_rope.getRotation()) * SIZE);

	while (current_location.y < 400.f && current_location.y >= 0 &&  current_location.x <700.f
		&& current_location.x>= 0)
	{
		current_location += (direction);
		//check the x y

		//cout << int(current_location.y / SIZE) << " " << int(current_location.x / SIZE) << endl;
		if (m_level(int((current_location.y / SIZE)), int((current_location.x / SIZE))) != nullptr)
		{
			
			cout << int((current_location.y / SIZE)) << " " << int((current_location.x / SIZE)) << endl;
			cout << "works the object is found " << endl;
			return true;
		}

			//cout << current_location.x << " " << current_location.y<<std:: endl;
	}
	//cout << m_rope.getRotation()<< endl;
	//cout << m_rope.get_position().y << " " << m_rope.get_position().x << endl;
	*/
	
//----------------------------------------------------------------------------------------------

