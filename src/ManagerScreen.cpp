#include "Screens/Screen.h"
#include "Screens/GameScreen.h"
#include "Screens/LevelScreen.h"
#include "Screens/StartScreen.h"
#include "Screens/MenuScreen.h"
#include "Screens/IntroductionScreen.h"
#include "Screens/GameOverScreen.h"
#include "Screens/GoalScreen.h"

#include <iostream>
#include <SFML/Graphics.hpp>

#include "ManagerScreen.h"



int ManagerScreen ::main_run()
{
	sf::RenderWindow GoldMiner(sf::VideoMode(640, 480), "Gold Miner");
	int screen = 0;

	std::vector<Screen*> Screens;


	create_screens(Screens);
	

	while (screen != -1)
	{
		screen = Screens[screen]->run(GoldMiner);
	}
}

//------------------------------------------------------------------------
void  ManagerScreen::create_screens(std::vector<Screen*> Screens)
{
	// start,  menu , introducction , level, goal , game , gameover

	StartScreen s0;
	Screens.push_back(&s0);

	MenuScreen s1;
	Screens.push_back(&s1);

	IntroductionScreen s2;
	Screens.push_back(&s2);

	LevelScreen s3;
	Screens.push_back(&s3);

	GoalScreen s4;
	Screens.push_back(&s4);

	GameScreen s5;
	Screens.push_back(&s5);

	GameOverScreen s6;
	Screens.push_back(&s6);



}