#include "Screens/Screen.h"
#include "Screens/GameScreen.h"
#include "Screens/StartScreen.h"
#include "Screens/MenuScreen.h"
#include "Screens/IntroductionScreen.h"
#include "Screens/GameOverScreen.h"
#include "Screens/GoalScreen.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ManagerScreen.h"



void ManagerScreen ::main_run()
{
	sf::RenderWindow GoldMiner({1200, 800}, "Gold Miner By Rachel Dekel and Esther Wahnon");
	GoldMiner.setFramerateLimit(60);
	int screen = 0;

	
	std::vector<Screen*> Screens;


	StartScreen s0;
	Screens.push_back(&s0);

	MenuScreen s1;
	Screens.push_back(&s1);

	IntroductionScreen s2;
	Screens.push_back(&s2);


	GoalScreen s3;
	Screens.push_back(&s3);

	GameScreen s4;
	Screens.push_back(&s4);

	GameOverScreen s5;
	Screens.push_back(&s5);
	create_screens(Screens);
	
	int level = 0;


	while (screen != -1)
	{
		screen = Screens[screen]->run(GoldMiner, level);
	
	}
}

//------------------------------------------------------------------------
void  ManagerScreen::create_screens(std::vector<Screen*> Screens)
{
	// start,  menu , introducction , goal , game , gameover
	


	
}