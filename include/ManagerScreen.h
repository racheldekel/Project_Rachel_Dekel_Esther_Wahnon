#pragma once
#include "Screens/Screen.h"

class ManagerScreen
{
public:

	ManagerScreen() {};
	~ManagerScreen() {};
	void main_run();

	void  create_screens(std::vector<Screen*> Screens);

private:
};
