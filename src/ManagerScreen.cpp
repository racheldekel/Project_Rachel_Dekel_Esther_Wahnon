//#include "Screens/Screen.h"

#include "ManagerScreen.h"



int ManagerScreen ::main_run()
{
	int screen = 0;

	while (screen != -1)
	{
		screen = Screens[screen]->run(App);
	}
}