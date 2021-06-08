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

						if (isAttach(gold_miner))
							cout << "is working";


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
		m_rope.update_state(clock.getElapsedTime()*10.f);
		float passedTime = clock.restart().asSeconds();
		//m_mouse.move(passedTime);

		sf::Vector2f pos = m_mouse.getPosition();
		m_mouse.setPosition(pos);
		m_rope.draw(gold_miner);
		gold_miner.display();
		
		gold_miner.clear();
		clock.restart();

		//m_rope.openRope(clock.getElapsedTime()*10.f);
		//m_rope.rotateRope(clock.getElapsedTime());

	}

	//return 1;
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
int Controller::mouse_button_released(sf::Event event)
{

	auto x1 = event.mouseButton.x;
	auto y1 = event.mouseButton.y;
	sf::Vector2i pos1(x1, y1);

	//cout << pos1.x << " " << pos1.y;
	if ((pos1.x > 534 && pos1.x < 581) && (pos1.y < 46 && pos1.y > 17))
		return EXIT;

	m_rope.changeState();

	
	// delete
	
	auto x = event.mouseButton.x;
	auto y = event.mouseButton.y;
	sf::Vector2i pos(x /SIZE, y/SIZE );
	
	

	//if (m_level(pos.y, pos.x))
		//cout << " here object " << endl;

		
		
	return 1;
}
//----------------------------------------------------------------
bool Controller::isAttach(sf::RenderWindow& window)
{
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


	return false;
}

//----------------------------------------------------------------------------------------------
void Controller::drawAllObject(sf::RenderWindow& gold_miner)
{

	m_level.draw_static_figures(gold_miner);
	m_toolbar.draw(gold_miner,  m_levelNumber, m_moneyCounter, m_goalLevel, m_time);
}

