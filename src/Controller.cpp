#include "Controller.h"
class ActionError{};

//const auto SIZE = 60;

void Controller::startGame(sf::RenderWindow& gold_miner)
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

		if (isAttach(gold_miner))
			cout << "is working";
		
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
					mouse_button_released(event);
					break;
				case sf::Event::KeyPressed:
					throw ActionError();

				}
			}
			catch (ActionError)
			{
				std::cout << "Please click the mouse" << std::endl;

			}
		}
		
		drawAllObject(gold_miner);
		m_player.draw(gold_miner);
		m_rope.update_state(clock.getElapsedTime()*10.f);
		//m_rope.openRope(clock.getElapsedTime()*10.f);
		//m_rope.rotateRope(clock.getElapsedTime());
		m_rope.draw(gold_miner);
		gold_miner.display();
		

		gold_miner.clear();
		clock.restart();
	}

	return;
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
void Controller::mouse_button_released(sf::Event event)
{
	m_rope.changeState();

	
	// delete
	
	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x /SIZE, y/SIZE );
	
	if (m_level(pos.y, pos.x))
		cout << " here object " << endl;

		
		

	
	
}
//----------------------------------------------------------------
bool Controller::isAttach(sf::RenderWindow& window)
{
	//Rope{ {400.f, 65.f} };
	auto current_location = sf::Vector2f{ 400.f,65.f };
	auto direction = sf::Vector2f(cosf(m_rope.getRotation()) * SIZE, sinf(m_rope.getRotation()) * SIZE);
	current_location += direction;
	if (m_level(current_location.x, current_location.y) != nullptr)
	{
		cout << "works the object is found " << endl;
		return true;
	}
	//cout << m_rope.getRotation()<< endl;
	//cout << m_rope.get_position().y << " " << m_rope.get_position().x << endl;
	cout << current_location.x << " " << current_location.y<<std:: endl;
	return false;
}

//----------------------------------------------------------------------------------------------
void Controller::drawAllObject(sf::RenderWindow& gold_miner)
{

	m_level.draw_static_figures(gold_miner);
	m_toolbar.draw(gold_miner,  m_levelNumber, m_moneyCounter, m_goalLevel, m_time);
}

